#include "LinkedList.h"
#include "Node.h"

// constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr){}
//Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    while(head)
    {
        Node<T> *temp = head;
        head = head.next;
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
bool LinkedList<T>::isEmpty() {head ? return true : return false;}

// returns size of list
template <typename T>
int LinkedList<T>::size()
{
    int size = 0;
    Iterator current = LinkedList.begin();
    while (current != LinkedList.end())
    {
        ++size;
        ++Iterator;
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
    if(temp1 == this->end()) {return head};
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