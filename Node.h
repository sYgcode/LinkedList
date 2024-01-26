#pragma once
//@author @sYgcode
template <typename T>
class Node
{
private:
public:
    T data;
    Node<T>* next;
    Node(T data);
    ~Node();
};

