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
    void LevelOrder()
    {
        Queue q(100);
        cout << root->data << " ";
        q.enqueue(root);
        while (!q.isEmpty())
        {
            root = q.dequeue();
            if (root->lchild)
            {
                cout << root->lchild->data << " ";
                q.enqueue(root->lchild);
            }
            if (root->rchild)
            {
                cout << root->rchild->data << " ";
                q.enqueue(root->rchild);
            }
        }
    }
};
int main()
{
    Tree t;
    t.createTree();
    cout << "Level Order" << endl;
    t.LevelOrder();
    cout << endl;
    return 0;
}