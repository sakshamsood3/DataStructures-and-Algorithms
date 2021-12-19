#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){};
    Node(int data)
    {
        lchild = NULL;
        this->data = data;
        rchild = NULL;
    }
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
    int searchInorder(int inArray[], int inStart, int inEnd, int data)
    {
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inArray[i] == data)
            {
                return i;
            }
        }
        return -1;
    }
    Node *generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
    {
        static int preIndex = 0;
        if (inStart > inEnd)
        {
            return NULL;
        }
        Node *node = new Node(preorder[preIndex++]);
        if (inStart == inEnd)
        {
            return node;
        }
        int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
        node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
        node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);
        return node;
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
};
int main()
{
    Tree t;
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    Node *T = t.generateFromTraversal(inorder, preorder, 0, (sizeof(inorder) / sizeof(inorder[0]) - 1));
    cout << "Pre Order" << endl;
    t.PreOrder(T);
    return 0;
}