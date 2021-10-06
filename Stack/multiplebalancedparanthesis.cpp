#include <iostream>
using namespace std;
class Stack
{
    int size;
    int top;
    char *s;

public:
    Stack()
    {
        size = 20;
        s = new char[size];
        top = -1;
    }
    Stack(int size)
    {
        this->size = size;
        s = new char[size];
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
    char peek(int pos)
    {
        char x = ' ';
        if (top - pos + 1 < 0)
            cout << "Invalid Position" << endl;
        else
            x = s[top - pos + 1];
        return x;
    }
    char StackTop()
    {
        if (top == -1)
            return ' ';
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
    bool isBalanced(char *exp)
    {
        char x;
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                push(exp[i]);
                continue;
            }
            if (isEmpty())
            {
                return false;
            }
            switch (exp[i])
            {
            case ')':

                // Store the top element in a
                x = StackTop();
                pop();
                if (x == '{' || x == '[')
                    return false;
                break;

            case '}':

                // Store the top element in b
                x = StackTop();
                pop();
                if (x == '(' || x == '[')
                    return false;
                break;

            case ']':
                // Store the top element in c
                x = StackTop();
                pop();
                if (x == '(' || x == '{')
                    return false;
                break;
            }
        }
        return (isEmpty());
    }
};
int main()
{
    Stack st(20);
    char exp[] = "[()]{}{[()()]()}";
    if (st.isBalanced(exp))
        cout << "Balanced Paranthesis " << endl;
    else
        cout << "Unbalanced Paranthesis" << endl;
    return 0;
}