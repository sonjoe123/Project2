#ifndef DSList_H
#define DSList_H
#include <iostream>
using namespace std;
/**
 * @brief Singly-linked list that uses position
 *
 * 1. Use a postion index to refer to an element. This is simpler to
 *    implement compared to iterators (see iterator version), but does not
 *    play as nicely with the STL.
 * 2. Use a sentinel node (a node without data that represents the
 *    begining of the list).
 * 
 * @tparam Object 
 */

template <typename Object>
class DSList
{
private:
    /**
      * @brief The Node data structure
      *
      * struct is a class with all public members
      */
    int size;
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {};
    };

public:

// You need to implement
// Default construction
    DSList();
// Copy constructor
    DSList(const DSList &oriObj);
//assignment operator
    DSList& operator=(const DSList &copyObj);
// square bracket operator
    Object &operator[](const int index);
// Destructor
    ~DSList();
// size
    int Size();
// empty?
    bool isEmpty();
// clear
    void clear();
// find an element with a specific value (and return the position. First element in list is pos 0).
    int searchElement(Object);
// insert in front (push_front).
    void push_front(Object);
// insert at a specified position.
    void insert_at(Object,int);
// remove the element in front (pop_front)
    void pop_front();
// remove using position.
    void remove_at(int);
// remove an element with a specific value (find and remove)
    void removeElement(Object);
// get the value of the tail
    Object getTail();

private:
    Node *head;
    Node *tail;


};
//Default construction
template <typename Object>
DSList<Object>::DSList() {
    head = nullptr;
    size = 0;
}
//Copy Constructor
template <typename  Object>
DSList<Object>::DSList(const DSList<Object> &oriObj) {
    if (oriObj.head == nullptr){
        size = 0;
        return;
    }
    Node* itr = oriObj.head;
    Node* curr;

    head = new Node;
    head->data = itr->data;
    head->next - nullptr;
    curr = head;

    while(itr != nullptr) {
        curr->next = new Node;
        curr = curr->next;
        curr->data = itr->data;
        curr->next = nullptr;
        itr = itr->next;
    }
}
// Destructor
template <typename Object>
DSList<Object>::~DSList() {
    clear();

}
// assignment operator
template <typename Object>
DSList<Object> &DSList<Object>::operator=(const DSList<Object> &copyObj) {
    clear();
    if (copyObj.head == nullptr){
        size = 0;
        return *this;
    }
    Node* itr = copyObj.head;
    Node* curr;

    head = new Node;
    head->data = itr->data;
    head->next - nullptr;
    curr = head;

    while(itr != nullptr) {
        curr->next = new Node;
        curr = curr->next;
        curr->data = itr->data;
        curr->next = nullptr;
        itr = itr->next;
    }
    return *this;
}
// square bracket operator
template <typename Object>
Object &DSList<Object>::operator[](const int index) {
    Node* itr = head;
    // Loop through the list and find the value at the index
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }
    return itr->data;
}
// clear
template <typename Object>
void DSList<Object>::clear() {
    Node* current = head;
    Node* previous = nullptr;
    while(current != nullptr){
        previous = current;
        current = current->next;
        delete previous;
    }
    head = nullptr;
    size = 0;
}
// remove using position
template <typename Object>
void DSList<Object>::remove_at(int index) {
    Node* current = head;
    Node* previous;

    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }
    if (current == head){
        head = current->next;
        delete current;
    }else{
        previous->next = current->next;
        delete current;
    }
    size -= 1;
}
//is Empty?
template <typename Object>
bool DSList<Object>::isEmpty() {
    if(size > 0){
        return false;
    } else{
        return true;
    }

}
// check for the size
template <typename Object>
int DSList<Object>::Size() {
    return size;
}
// insert in front (push_front).
template <typename Object>
void DSList<Object>::push_front(Object value) {
    Node* newNode;
    newNode = new Node;
    newNode->next = nullptr;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    size +=1;
}
// insert at a specific position
template <typename Object>
void DSList<Object>::insert_at(Object value, int pos) {
    Node* cur = head;
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    if(pos == 0){
        head = temp;
        head->next = cur;
    } else {
        int count = 0;
        Node* previous = new Node;
        while(count != pos){
            if(count == (pos - 1)){
                previous = cur;
            }
            cur = cur->next;
            count ++;
        }
        previous->next = temp;
        temp->next = cur;
    }
    size +=1;
}
// remove the element in the front
template <typename Object>
void DSList<Object>::pop_front() {
    if(head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }


    size -=1;
}
// find an element with a specific value (and return the position. First element in list is pos 0).
template <typename Object>
int DSList<Object>::searchElement(Object value) {
    Node* temp = head;
    // create two tracking:
    // first one to track the current index
    // second one to track the found value
    int  i = 0;
    // If the temp is not null -> loop through the linklist, if found -> break the loop else continue to loop until find the value
    while(temp != nullptr){
        i++;
        if(temp->data == value){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}
template <typename  Object>
void DSList<Object> ::removeElement(Object value) {
    if(head){
        remove_at(searchElement(value));
    }else{
        cout<< "Out of range" << endl;
    }
}
template <typename Object>
Object DSList<Object>::getTail(){
    Node* temp = head;
    return temp->data;
}
#endif
