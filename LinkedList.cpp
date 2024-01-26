#include "LinkedList.h"
#include "Node.h"

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr){}
//Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    while(head)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

//adds 2 lists together
template <typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList& list)
{
    this->back().next = list.head;
}

//returns a boolean of the List is empty
template <typename T>
bool LinkedList<T>::isEmpty() 
{
    if(head != nullptr) 
    {return true;}
    else 
    {return false;}
}

// returns size of list
template <typename T>
int LinkedList<T>::size()
{
    int size = 0;
    Iterator current = this->begin();
    while (current != this->end())
    {
        ++size;
        ++current;
    }
    return size;
}

//returns pointer to first element in list
template <typename T>
Node<T>* LinkedList<T>::front() {return head;}

//returns pointer to last element in list
template <typename T>
Node<T>* LinkedList<T>::back() 
{
    Iterator temp1= this->begin();
    Iterator temp2 = temp1;
    if(temp1 == this->end()) {return head;}
    ++temp1;
    while (temp1 != this->end())
    {
        ++temp1;
        ++temp2;
    }
    return temp2.current;
}

//adds a new element to the front
template <typename T>
void LinkedList<T>::push_front(T data)
{
    Node<T>* newHead = new Node<T>(data);
    newHead->next = head;
    head = newHead;
}

//removes first element
template <typename T>
void LinkedList<T>::pop_front()
{
    if(head == nullptr) {return;}
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

//removes everything from the list
template <typename T>
void LinkedList<T>::clear()
{
    Node<T>* temp;
    while(head != nullptr)
    {
        pop_front();
    }
}

//inserts a new node at the given spot
template <typename T>
void LinkedList<T>::insert(Iterator i, T data)
{
    if(i == this.end()) {push_back(data);}
    Node<T>* newNode = new Node<T>(data);
    newNode->next = i.current->next;
    i.current->next = newNode;
}

//adds a new node to the end
template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->next = nullptr;
    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    this.back()->next = newNode;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if(head == nullptr) {return;}
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* curr = head;
    while (curr->next->next != nullptr)
    {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return Iterator(head);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    return Iterator(nullptr);
}