#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
public:
    class Iterator;
    LinkedList();
    ~LinkedList();
    LinkedList operator+(const LinkedList& list);
    bool isEmpty();
    int size();
    Node<T>* front();
    Node<T>* back();
    void push_front(T data);
    void pop_front();
    void clear();
    void insert(Iterator i, T data);
    void push_back(T data);
    void pop_back();
    void sort();
    Iterator begin();
    Iterator end();
};

// Definition of the Iterator class
template <typename T>
class LinkedList<T>::Iterator
{
private:
    Node<T>* current;

public:
    Iterator(Node<T>* start) : current(start) {}

    // Overload the dereference operator (*) to get the value at the current node
    T& operator*() const {
        return current->data;
    }

    // Overload the pre-increment operator (++it) to move to the next node
    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    // Overload the inequality operator (!=) to check for inequality
    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};

