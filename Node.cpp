#include "Node.h"
template <typename T>
Node<T>::Node(T data, Node<T>* next)
{
    this->data = data;
    this->next = next;
}

template <typename T>
Node<T>::~Node()
{
    if(next)
        delete next;
    next = nullptr;
}
