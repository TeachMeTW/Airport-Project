#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linkedlistfunctionsTemplated.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/airport/simulation.h"

//------------------------------------------------------------------------------------------
//Files we are testing:



//------------------------------------------------------------------------------------------

using namespace std;

bool test_linked_list_functions(bool debug = false) {
    cout << "\nTesting Linked List Functions" << endl;
    node<int>* headptr = NULL;  // must initialize headptr
    node<int>* copy = NULL;
    for (int i = 0; i<100; i+= 10) {
        _insert_head(headptr, i);
        _print_list(headptr);
        cout << endl;
    }   
    _print_list(headptr);
    cout<<endl;
    cout << "\nPrinting Backwards:" << endl;
    _print_list_backwards(headptr);
    cout << endl;
    node<int> *this_node;
    this_node = _search_list(headptr, 10);
    cout << "\nAbout to delete " << *this_node << endl;
    _delete_node(headptr, this_node);
    _print_list(headptr);
    cout<<endl;
    cout << "Find 20: " << endl;
    this_node = _search_list(headptr, 20);
    cout << "Insert 69 before 20: " << endl;
    _insert_before(headptr,this_node, 69);
    _print_list(headptr);
    cout << endl;
    this_node = NULL;
    cout << "Insert 420 after null: " << endl;
    _insert_after(headptr,this_node, 420);
    _print_list(headptr);
    cout << endl;
    cout << "Search for 60: " << endl;
    this_node = _search_list(headptr, 60);
    cout << "Previous to 60 is: " << endl;
    cout << *(_previous_node(this_node));
    cout << "\n\nCopying to new node/list :\n" << endl;
    copy = _copy_list(headptr);
    _print_list(copy);
    cout << endl << endl;
    cout << "Find whats at 4: " << endl;
    cout << _at(copy, 4) << " is found";
    cout << endl;
    cout << "Removing head from original: " << endl;
    _remove_head(headptr);
    cout << "original: ";
    _print_list(headptr);
    cout << endl;
    cout << "Copy: " << endl;
    _print_list(copy);
    cout << endl;
    cout << "Removing head from copy" << endl;
    _remove_head(copy);
    _print_list(copy);
    cout << endl;
    cout << "Removing head from copy" << endl;
    _remove_head(copy);
    _print_list(copy);
    cout << endl;
    cout << "Adding value to original: " << endl;
    _insert_head(headptr, 69420);
    cout << endl << endl;
    cout << "Original: ";
    _print_list(headptr);
    cout << endl;
    cout << "Copy: ";
    _print_list(copy);
    cout << endl << endl;
    cout << "Clearing list: " << endl;
    _clear_list(headptr);
    _print_list(headptr);
    cout << endl;
    cout << "Insert 5: " << endl;
    _insert_head(headptr, 5);
    _print_list(headptr);
    cout << endl;
    cout << "Insert 65: " << endl;
    _insert_head(headptr, 65);
    _print_list(headptr);
    cout << endl;
    this_node = NULL;
    cout << "Search for 5: " << endl;
    cout << "Found: " << endl;
    this_node = _search_list(headptr,5);
    cout << *this_node << endl;
    cout << "Delete 5: " << endl;
    _delete_node(headptr, this_node);
    _print_list(headptr);
    cout << endl;
    cout << "Remove head:" << endl;
    _remove_head(headptr);
    _print_list(headptr);
    cout << endl << endl;
    return true;
}

bool test_queue(bool debug = false) {
    cout << "\nTesting Queue" << endl;
    Queue<int> q;
    for (int i = 100; i>= 0; i-=10) {
        q.push(i);
        cout << q.size() << endl;
        cout << q << endl;
    }
    for(Queue<int>::Iterator it = q.begin(); it != q.end(); it++){
    cout << "it->>" << *it << endl;
    }
    cout << endl;
    cout << "Testing front:" << endl;
    cout << "Current front: "<< q.front();
    cout << endl;
    cout << "Popped: " << q.pop();
    cout << endl;
    cout << "Next front: " << q.front();
    cout << endl;
    cout << "Current Queue: " << endl;
    cout << q << endl << "Size: " << q.size() << endl;
    cout << endl;

    //cout << "Testing Copy Const" << endl;
    //Queue<int> r(q);
    //cout << "The copy of original: " << endl; 
    //cout << r << endl;
    //cout << q << endl;
    //r.pop();
    //cout << r << endl;
    //cout << q << endl;
    // cout << "Popping 1 value from copy" << endl;
    // r.pop();
    // cout << r << endl;
    // cout << "Testing assignment operator:" << endl;
    // Queue<int> p = q;
    // cout << p << endl;
    cout << "\nTesting Queue Pop for original" << endl;
    while (q.size() > 0) {
        q.pop();
        cout << q << endl;
    }
    cout << "Popped all";
    cout << endl << endl;
    return true;
}


bool test_stack(bool debug = false) {
    cout << "\nTesting Stack" << endl;
    Stack<int> s;
    for (int i = 100; i>= 0; i-=10) {
        s.push(i);
        cout << s.size() << endl;
        cout << s << endl;
    }
    for(Stack<int>::Iterator it = s.begin(); it != s.end(); it++){
    cout << "it->>" << *it << endl;
    }
    cout << endl;
    cout << "Testing Top:" << endl;
    cout << "Current top: "<< s.top();
    cout << endl;
    cout << "Popped: " << s.pop();
    cout << endl;
    cout << "Next top: " << s.top();
    cout << endl;
    cout << "Current stack: " << endl;
    cout << s << endl << "Size: " << s.size() << endl;
    cout << endl;
    cout << "Testing Copy Const Stack c(Stack s)" << endl;
    Stack<int> c(s);
    cout << "The copy of original: " << endl; 
    cout << c << endl;
    cout << "Popping from the copy: " << endl;
    c.pop();
    cout << c << endl;
    cout << "Testing assignment operator Stack b = Stack s: ";
    Stack<int> b = s;
    cout << endl;
    cout << b;
    cout << endl;
    cout << "Current stack: " << endl;
    cout << s;
    cout << endl;
    cout << "\nTesting Stack Pop" << endl;
    while (s.size() > 0) {
        s.pop();
        cout << s << endl;
    }
    cout << endl;
    return true;
}

bool test_simulation(bool debug = false) {
  cout<<endl<<endl<<"======================================="<<endl<<endl;
  srand(time(nullptr));
  for (int i=0; i<30; i++) {
    cout << "---------------------- [" << i << "] ---------------------------" << endl;
    simulate_airport(debug = false);
  }
  
  return true;
}


TEST(TEST_FUNCTIONS, TestLinkedListFunctions) {
  bool success = test_linked_list_functions(true);
  EXPECT_EQ(success, true);
}


TEST(TEST_QUEUE, TestQueue) {
  bool success = test_queue(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_STACK, TestStack) {
  bool success = test_stack(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_SIMULATION, test_simulation) {
  bool success = test_simulation(true);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
