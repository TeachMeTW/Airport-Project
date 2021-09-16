
#include "../../includes/airport/simulation.h"
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linkedlistfunctionsTemplated.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;


// take off probabilty; assert it fits
// between 0 < p < 1
take_off::take_off(double p) {
    assert(p >= 0);
    assert(p <= 1);
    take_off_probability = p;
}

// randomizer if plane is leaving
bool take_off::query() const {
    return (rand() < take_off_probability * RAND_MAX);
}

// landing probability assert it fits
// between 0 < p < 1
landing::landing(double p) {
    assert(p >= 0);
    assert(p <= 1);
    landing_probability = p;
}

// randomizer if plane is arriving
bool landing::query() const {
    return (rand() < landing_probability * RAND_MAX);
}

// averager constructor
averager::averager() {
    count = 0;
    sum = 0;
}

// averager stores the values for future calculation
void averager::next_num(double value) {
    ++count;
    sum += value;
}

// averages total over numbers counted
double averager::average() const {
    // assert number of values is greater than 0
    assert(how_many() > 0);
    return sum/count;
}

// determines how a plane lands
// sets the landing time and time it takes
landing_system::landing_system(unsigned int landing_time) {
    seconds_landing = landing_time;
    remaining_time = 0;
}

// starts the landing countdown
void landing_system::start_landing() {
    // checks if landing is occuring
    assert(!is_landing());
    remaining_time = seconds_landing;
}

// simulates 1 second has passed
void landing_system::one_sec() {
    // check if landing is occuring
    if (is_landing()) {
        --remaining_time;
    }
}

// when a plane crashes it's time resets
void landing_system::crashed() {
    remaining_time = 0;
}

// determines how a plane takes off
take_off_system::take_off_system(unsigned int take_off_time) {
    seconds_taking_off = take_off_time;
    remaining_time = 0;
}

// starts the takeoff countdown
void take_off_system::start_take_off() {
    // checks if theres a takeoff in progress
    assert(!is_take_off());
    remaining_time = seconds_taking_off;
}

// simulates 1 second
void take_off_system::one_sec() {
    // checks if its taking off
    if (is_take_off()) {
        --remaining_time;
    }
}

// debugging purpose to see current time
void take_off_system::get_time() {
    cout << remaining_time;
}

void simulate_airport (bool debug = false) {
    // Simulation parameters
    unsigned int land_time =5;
    unsigned int take_off_time = 15;
    double take_off_prob = 0.08; 
    double landing_prob = 0.10;
    unsigned int total_time = 1440;
    unsigned int fuel_limit = 20;

    // Create 2 queues to simulate arrivals and departures
    Queue<unsigned int> arrivals;
    Queue<unsigned int> departures;

    // Set variables for next in line and crashed planes
    unsigned int next_landing;
    unsigned int next_take_off;
    unsigned int crashed;

    // sets the probability and randomness of getting a plane
    // to leave or arrive
    take_off leaving(take_off_prob);
    landing arriving(landing_prob);

    // creates the landing/take off system
    // takes the landing/take off time as parameters
    landing_system lander(land_time);
    take_off_system flyer(take_off_time);

    // creates an averager for take off and landing time
    averager take_off_avg;
    averager landing_avg;

    // variable for current simulated second
    unsigned int current_second;
    if (debug) {
        cout << "Seconds to land: " << land_time << endl;
        cout << "Seconds to take off: " << take_off_time << endl;
        cout << "Probability of Landing: " << landing_prob << endl;
        cout << "Probablity of Take off: " << take_off_prob << endl;
        cout << "Fuel: Time before death: " << fuel_limit << endl;
        cout << "Total Simulation Time: " << total_time << endl;
    }
    
    // Cycles until total time is reached
    for (current_second = 1; current_second <= total_time; ++current_second) {
        
        // if plane is found to be leaving
        if (leaving.query()) {
            // push current time
            departures.push(current_second);
        }
        
        // if plane is found to be arriving
        if (arriving.query()) {
            // push current time
            arrivals.push(current_second);
        }

        // if there is no planes flying and no planes landing
        if ((!flyer.is_take_off() && !lander.is_landing())) {       
            // if theres no planes flying and landing and arrivals are empty    
            if ((!flyer.is_take_off()) && (!lander.is_landing() && (!arrivals.empty()))) {
                // next landing is the front of the queue
                next_landing = arrivals.front();       
                // if the time till next landing is past the fuel
                // the plane crashes
                if ((current_second - next_landing) > fuel_limit) {
                    lander.crashed();
                    crashed++;
                }
                // pop the front
                arrivals.pop();
                // takes the wait time and stores it in the averager
                landing_avg.next_num(current_second - next_landing);
                // start the landing process
                lander.start_landing();
            }

            // if theres no plane landing and flying and departures are empty
            if ((!lander.is_landing()) && (!flyer.is_take_off() && (!departures.empty()))) {
                // next take off is front of queue
                next_take_off = departures.front();
                // pop the front
                departures.pop();
                // stores the time into averager
                take_off_avg.next_num(current_second - next_take_off);
                // start take off process
                flyer.start_take_off();

            }

        }
        // move the time 1 second for the landing and takeoff
        lander.one_sec();
        flyer.one_sec();
    }
    if (debug) {
        cout << "\nDeparture Queue size: " << departures.size() << " planes awaiting take off" << endl << endl;
        cout << "Arrival Queue size: " << arrivals.size() << " planes ready to land" << endl << endl;
        cout << "Planes arrived: " << landing_avg.how_many() << endl;
        cout << "Planes departed: " << take_off_avg.how_many() << endl;
        cout << "Planes crashed: " << crashed << endl;
        if (landing_avg.how_many() > 0) {
            cout << "Average wait to land: " << landing_avg.average() << " seconds" << endl;
        } 
        if (take_off_avg.how_many() > 0) {
            cout << "Average wait to leave: " << take_off_avg.average() << " seconds" << endl;
        }
    }
    
}
