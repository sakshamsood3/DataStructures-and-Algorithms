#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
class Queue
{
    int size;
    int rear;
    int front;
    Node **Q;

public:
    Queue()
    {
        size = 5;
        Q = new Node *[size];
        rear = front = -1;
    }
    Queue(int size)
    {
        this->size = size;
        Q = new Node *[size];
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
    void enqueue(Node *x)
    {
        if (isFull())
            cout << "Queue is Full" << endl;
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    Node *dequeue()
    {
        Node *x = NULL;
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
    Node *root;

public:
    Tree() { root = NULL; };
    void createTree()
    {
        Node *p, *t;
        int x;
        Queue q(100);
        cout << "Enter root value" << endl;
        cin >> x;
        root = new Node;
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
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "Enter right child" << endl; //-1 symbolises no child
            cin >> x;
            if (x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }
    void PreOrder(Node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            PreOrder(p->lchild);
            PreOrder(p->rchild);
        }
    }
    void InOrder(Node *p)
    {
        if (p)
        {
            InOrder(p->lchild);
            cout << p->data << " ";
            InOrder(p->rchild);
        }
    }
    void PostOrder(Node *p)
    {
        if (p)
        {
            PostOrder(p->lchild);
            PostOrder(p->rchild);
            cout << p->data << " ";
        }
    }
    int Height(Node *root)
    {
        int x = 0, y = 0;
        if (root == NULL)
            return 0;
        x = Height(root->lchild);
        y = Height(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    int Height()
    {
        Height(root);
    }
    void PreOrder()
    {
        PreOrder(root);
    }
    void InOrder()
    {
        InOrder(root);
    }
    void PostOrder()
    {
        PostOrder(root);
    }
};
int main()
{
    Tree t;
    t.createTree();
    cout << "Pre Order" << endl;
    t.PreOrder();
    cout << endl;
    cout << "Height of the Binary Tree is " << t.Height() << endl;
    return 0;
}