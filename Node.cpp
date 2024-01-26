#include "Node.h"
template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}

template <typename T>
Node<T>::~Node()
{
    if(next)
        delete next;
    next = nullptr;
}
