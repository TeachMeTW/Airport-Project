#ifndef SIMULATION_H
#define SIMULATION_H

#include <cstdlib>
using namespace std;

// take of probability
class take_off {
    public:
        // constructor takes double | default is set to 0.08
        take_off(double p = 0.08);
        // if plane is taking off
        bool query() const;
    private:
        double take_off_probability;
};

// landing probability
class landing {
    public:
        // constructor takes double | default is set to 0.10
        landing(double p = 0.10);
        // if plane is landing
        bool query() const;
    private:
        double landing_probability;
};

// Averager class
// Averages values stored and counts number of values
class averager {
    public:
        averager();
        void next_num(double value);
        size_t how_many() const {return count;}
        double average() const;
    private:
        size_t count;
        double sum;
};

// Landing system for airport
class landing_system {
    public:
        // constructor takes landing time uint | default is 5
        landing_system(unsigned int landing_time = 5);
        // one second simulator
        void one_sec();
        // signals a landing
        void start_landing();
        // signals a plane crashed
        void crashed();
        // checks if plane is landing
        bool is_landing() const { return (remaining_time > 0);}
    private:
        unsigned int seconds_landing;
        unsigned int remaining_time;
};

// Landing system for airport
class take_off_system {
    public:
        // constructor takes take off time uint | default 15
        take_off_system(unsigned int take_off_time = 15);
        // one second simulator
        void one_sec();
        // signals a take off
        void start_take_off();
        // gets current time (debug feature)
        void get_time();
        // checks if plane is taking off
        bool is_take_off() const { return (remaining_time > 0);}
    private:
        unsigned int seconds_taking_off;
        unsigned int remaining_time;
};

// function prototype
void simulate_airport (bool debug);


#endif // SIMULATION_H