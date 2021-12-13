#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *lchild;
    TreeNode *rchild;
};
class Stack
{
    int size;
    int top;
    TreeNode **s;

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
        s = new TreeNode *[size];
        top = -1;
    }
    Stack(int size)
    {
        this->size = size;
        s = new TreeNode *[size];
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
    void push(TreeNode *ele)
    {
        if (top == size - 1)
            cout << "Stack overflow" << endl;
        else
        {
            top++;
            s[top] = ele;
        }
    }
    TreeNode *pop()
    {
        TreeNode *x = NULL;
        if (top == -1)
            cout << "Stack underflow" << endl;
        else
        {
            x = s[top];
            top--;
        }
        return x;
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
class Queue
{
    int size;
    int rear;
    int front;
    TreeNode **Q;

public:
    Queue()
    {
        size = 5;
        Q = new TreeNode *[size];
        rear = front = -1;
    }
    Queue(int size)
    {
        this->size = size;
        Q = new TreeNode *[size];
        front = rear = -1;
    }
    ~Queue()
    {
        delete[] Q;
    }
    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }
    void enqueue(TreeNode *x)
    {
        if (isFull())
            cout << "Queue is Full" << endl;
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    TreeNode *dequeue()
    {
        TreeNode *x = NULL;
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }
};
class Tree
{
    TreeNode *root;

public:
    Tree() { root = NULL; };
    void createTree()
    {
        TreeNode *p, *t;
        int x;
        Queue q(100);
        cout << "Enter root value" << endl;
        cin >> x;
        root = new TreeNode;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);
        while (!q.isEmpty())
        {
            p = q.dequeue();
            cout << "Enter left child" << endl; //-1 symbolises no child
            cin >> x;
            if (x != -1)
            {
                t = new TreeNode;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "Enter right child" << endl; //-1 symbolises no child
            cin >> x;
            if (x != -1)
            {
                t = new TreeNode;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }
    void InOrder(TreeNode *t)
    {
        Stack st;
        while (t != NULL || !st.isEmpty())
        {
            if (t != NULL)
            {
                st.push(t);
                t = t->lchild;
            }
            else
            {
                t = st.pop();
                cout << t->data << " ";
                t = t->rchild;
            }
        }
    }
    void InOrder()
    {
        InOrder(root);
    }
};
int main()
{
    Tree t;
    t.createTree();
    cout << "In Order" << endl;
    t.InOrder();
    cout << endl;
    return 0;
}