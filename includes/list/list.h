#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iomanip>
#include "../../includes/linked_list_functions/linkedlistfunctionsTemplated.h"
#include <cassert>
using namespace std;


template<typename T>
class List{
    public:
    // constructors:
        List();
        List(T a[], int size);

    // big three
        List(const List& other);  // Copy const
        List<T>& operator =(const List &rhs);  // assignment operator
        ~List();  // destructor
    
    // Ostream operator
        friend ostream& operator <<(ostream& outs, const List& list) {
            _print_list(list._headptr);
            return outs;
        }
    // Function Prototypes
        node<T>* insert_head(const T &item);
        void print_list_backwards();
        void clr();
        T& at(int pos);
        node<T>* copylist();
        node<T>* search_list(T key);
        T delete_node(node<T>* delete_this);
        node<T>* insert_after(node<T> *after_this, T insert_this);
        node<T>* insert_before(node<T> *after_this, T insert_this);

    private:
        node<T> *_headptr;
};

template<typename T>
List<T>::List() {
   _headptr = nullptr;
}

template<typename T>    
List<T>::List(T a[], int size) {
    // go through array (backwards) and insert head into the List
    for (int i = size-1; i >= 0; i--) {
        insert_head(a[i]);
    }
}

template<typename T>
List<T>::List(const List& other) {
    // initialize headptr and initialize copy function
    _headptr = other._headptr;
    copylist();
} 

template<typename T>
List<T>& List<T>::operator= (const List& rhs) {
    if (_headptr != NULL) {clr();}
    _copy_list(rhs);
    // if headptr is not null, call clear_list to clear the existing list
    // call copy list and copy rhs into this
    return *this;
} 

template<typename T>
List<T>::~List() {
    clr();
    _headptr = NULL;

    // call clear list
    // set headptr to null
} 

template<typename T>
node<T>* List<T>::insert_head(const T &item) {
    return _insert_head(_headptr, item);
}

template<typename T>
void List<T>::print_list_backwards() {
    return _print_list_backwards(_headptr);
}

template<typename T>
void List<T>::clr() {
    _clear_list(_headptr);
}

template<typename T>
node<T>* List<T>::copylist() {
    return _copy_list(_headptr);
}

template <typename T>
T& List<T>::at(int pos) {
    return _at(_headptr, pos);
}

template <typename T>
node<T>* List<T>::search_list(T key) {
    return _search_list(_headptr, key);
}

template <typename T>
T List<T>::delete_node(node<T>* delete_this) {
    return _delete_node(_headptr, delete_this);
}

template <typename T>
node<T>* List<T>::insert_after(node<T> *after_this, T insert_this) {
    return _insert_after(_headptr, after_this, insert_this);
}

template <typename T>
node<T>* List<T>::insert_before(node<T> *before_this, T insert_this) {
    return _insert_before(_headptr, before_this, insert_this);
}

#endif // LIST_H