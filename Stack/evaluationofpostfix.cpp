#include <iostream>
#include <cstring>
#include <stdlib.h>
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
    int isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return 0;
        else
            return 1;
    }
    int isPre(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        return 0;
    }
    char *InftoPost(char *infix)
    {
        int i = 0, j = 0;
        char *postfix;
        int len = strlen(infix);
        postfix = (char *)malloc((len + 1) * sizeof(char));
        while (infix[i] != '\0')
        {
            if (isOperand(infix[i]))
                postfix[j++] = infix[i++];
            else
            {
                if (isPre(infix[i]) > isPre(StackTop()))
                    push(infix[i++]);
                else
                    postfix[j++] = pop();
            }
        }
        while (top != NULL)
        {
            postfix[j++] = pop();
        }
        postfix[j] = '\0';
        return postfix;
    }
    int Eval(char *postfix)
    {
        int i, x1, x2, r;
        for (i = 0; postfix[i] != '\0'; i++)
        {
            if (isOperand(postfix[i]))
                push(postfix[i] - '0');
            else
            {
                x2 = pop();
                x1 = pop();
                switch (postfix[i])
                {
                case '+':
                {
                    r = x1 + x2;
                    break;
                }
                case '-':
                {
                    r = x1 - x2;
                    break;
                }
                case '*':
                {
                    r = x1 * x2;
                    break;
                }
                case '/':
                {
                    r = x1 / x2;
                    break;
                }
                default:
                    break;
                }
                push(r);
            }
        }
        return pop();
    }
};
int main()
{
    char infix[] = "234*+82/-";
    int len = strlen(infix);
    Stack st(len + 1);
    st.push('#');
    char *postfix = st.InftoPost(infix);
    cout << postfix << endl;
    int ans = st.Eval(infix);
    cout << ans << endl;
    return 0;
}