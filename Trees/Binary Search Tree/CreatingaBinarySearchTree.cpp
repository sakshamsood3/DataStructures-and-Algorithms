#include <iostream>
using namespace std;
class Node
{
public:
    Node *lchild;
    Node *rchild;
    int data;
};
class BST
{
    Node *root;

public:
    Bst() { root = NULL; };
    void Insert(int key)
    {
        Node *t = root;
        Node *r, *p;
        if (root == NULL)
        {
            p = new Node;
            p->data = key;
            p->lchild = p->rchild = NULL;
            root = p;
            return;
        }
        while (t != NULL)
        {
            r = t;
            if (key < t->data)
                t = t->lchild;
            else if (key > t->data)
                t = t->rchild;
            else
                return;
        }
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        if (key < r->data)
            r->lchild = p;
        else
            r->rchild = p;
    }
    void Inorder(Node *p)
    {
        if (p)
        {
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }
    void Inorder()
    {
        Inorder(root);
    }
    Node *Search(int key)
    {
        Node *t = root;
        while (t != NULL)
        {
            if (t->data == key)
                return t;
            else if (key < t->data)
                t = t->lchild;
            else
                t = t->rchild;
        }
        return NULL;
    }
};
int main()
{
    Node *temp;
    BST t;
    t.Insert(10);
    t.Insert(5);
    t.Insert(20);
    t.Insert(8);
    t.Insert(30);
    cout << "In order" << endl;
    t.Inorder();
    cout << endl;
    temp = t.Search(20);
    if (temp != NULL)
        cout << "Element " << temp->data << " is found" << endl;
    else
        cout << "Element not found in the given Bst" << endl;
    return 0;
}