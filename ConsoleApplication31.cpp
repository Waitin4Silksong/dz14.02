
#include <iostream>
#include <string>

template <class T>
class Stack
{
public:
    template <class T1>
    class Node
    {
    public:
        T1 data;
        Node<T1>* nextNode;
    public:
        Node()
        {
            data = T1();
            nextNode = nullptr;
        }
        Node(T1 data_) : data{ data_ }, nextNode{ nullptr } {}
    };
    Node<T>* head;
    int length;
public:
    Stack() : head{ nullptr }, length{ 0 } {}
    ~Stack()
    {
        delete[] head;
    }
    void push(T value);
    void pop();
    bool empty();
    int size();
    T top();
    friend std::ostream& operator<<(std::ostream& out, const Stack<T>& stack)
    {
        Node<T>* temp = stack.head;
        while (temp != nullptr)
        {
            out << temp->data << " ";
            temp = temp->nextNode;
        }
        return out;
    }
};
template<class T>
void Stack<T>::push(T value)
{
    Node<T>* newNode = new Node<T>(value);
    length++;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node<T>* tmp = head;
    while (tmp->nextNode != nullptr)
    {
        tmp = tmp->nextNode;
    }

    tmp->nextNode = newNode;
}

template<class T>
void Stack<T>::pop()
{
    if (empty())
    {
        std::cout << "Stack is empty";
        return;
    }
    Node<T>* temp = head;
    head = head->nextNode;
    delete temp;
    length--;
}

template<class T>
bool Stack<T>::empty()
{
    return head == nullptr;
}

template<class T>
int Stack<T>::size()
{
    return length;
}

template<class T>
T Stack<T>::top()
{
    if (empty())
    {
        std::cout << "D";
        return T();
    }
    return head->data;
}

int main()
{
    Stack<int> stack;
    for (size_t i = 0; i < 10; i++)
    {
        stack.push(i);
    }
    std::cout << "Top: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Top: " << stack.top() << std::endl;
    std::cout << "Size: " << stack.size();

}


