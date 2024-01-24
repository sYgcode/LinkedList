
//author: @sYgcode
template <typename T>
class Node
{
private:
    T data;
    Node<T>* next;
public:
    Node(T data, Node<T>* next);
    ~Node();
};

