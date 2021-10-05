#include <iostream>
using namespace std;
class Stack
{
    int size;
    int top;
    int *s;

public:
    void setSize(int s)
    {
        this->size = s;
    }
    int getSize()
    {
        return this->size;
    }
    Stack()
    {
        size = 4;
        s = new int[size];
        top = -1;
    }
    Stack(int size)
    {
        this->size = size;
        s = new int[size];
        top = -1;
    }
    ~Stack()
    {
        delete[] s;
    }
    void Display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << s[i] << " ";
        }
    }
    void push(int ele)
    {
        if (top == size - 1)
            cout << "Stack overflow" << endl;
        else
        {
            cout << "Push operation successfull" << endl;
            top++;
            s[top] = ele;
        }
    }
    int pop()
    {
        int x = -1;
        if (top == -1)
            cout << "Stack underflow" << endl;
        else
        {
            cout << "Pop successfull" << endl;
            x = s[top];
            top--;
        }
        return x;
    }
    int peek(int pos)
    {
        int x = -1;
        if (top - pos + 1 < 0)
            cout << "Invalid Position" << endl;
        else
            x = s[top - pos + 1];
        return x;
    }
    int StackTop()
    {
        if (top == -1)
            return -1;
        else
            return s[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }
};
int main()
{
    int size;
    cout << "Enter the size of stack you want" << endl;
    cin >> size;
    Stack st(size);
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