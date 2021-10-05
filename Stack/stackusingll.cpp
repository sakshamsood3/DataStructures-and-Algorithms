#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
    Node *Top;

public:
    Stack()
    {
        Top = NULL;
    }
    void Display()
    {
        Node *p = Top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void push(int x)
    {
        Node *t = new Node;
        if (t == NULL)
            cout << "Stack overflow" << endl;
        else
        {
            cout << "Push operation successfull" << endl;
            t->data = x;
            t->next = Top;
            Top = t;
        }
    }
    int pop()
    {
        int x = -1;
        if (Top == NULL)
            cout << "Stack underflow" << endl;
        else
        {
            Node *p = Top;
            x = p->data;
            Top = Top->next;
            delete p;
        }
        return x;
    }
    int peek(int pos)
    {
        Node *p = Top;
        for (int i = 0; p != NULL && i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p != NULL)
            return p->data;
        else
            return -1;
    }
    int StackTop()
    {
        if (Top)
            return Top->data;
        else
            return -1;
    }
    bool isEmpty()
    {
        return Top ? false : true;
    }
    int isFull()
    {
        Node *t = new Node;
        int r = t ? 0 : 1;
        delete t;
        return r;
    }
};
int main()
{
    Stack st;
    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
        cout << "stack is not empty" << endl;
    st.push(20);
    st.push(40);
    st.push(30);
    st.push(50);
    st.push(60);
    if (st.isFull())
        cout << "Stack is full" << endl;
    else
        cout << "stack is not full" << endl;
    st.pop();
    cout << st.peek(2) << endl;
    st.Display();
    return 0;
}