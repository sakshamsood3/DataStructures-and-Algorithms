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
public:
    Node *root;
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
    Node *RInsert(Node *p, int key)
    {
        Node *t;
        if (p == NULL)
        {
            t = new Node;
            t->data = key;
            t->lchild = t->rchild = NULL;
            return t;
        }
        if (key < p->data)
            p->lchild = RInsert(p->lchild, key);
        else if (key > p->data)
            p->rchild = RInsert(p->rchild, key);
        return p;
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
    Node *InPre(Node *p)
    {
        while (p && p->rchild != NULL)
        {
            p = p->rchild;
        }
        return p;
    }
    Node *InSucc(Node *p)
    {
        while (p && p->lchild != NULL)
        {
            p = p->lchild;
        }
        return p;
    }
    Node *Delete(Node *p, int key)
    {
        Node *q;
        if (p == NULL)
            return NULL;
        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
                root = NULL;
            delete p;
            return NULL;
        }
        if (key < p->data)
            p->lchild = Delete(p->lchild, key);
        else if (key > p->data)
            p->rchild = Delete(p->rchild, key);
        else
        {
            if (Height(p->lchild) > Height(p->rchild))
            {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else
            {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
    }
};
int main()
{
    Node *temp;
    BST t;
    t.root = t.RInsert(t.root, 50);
    t.RInsert(t.root, 10);
    t.RInsert(t.root, 40);
    t.RInsert(t.root, 20);
    t.RInsert(t.root, 30);
    cout << "In order" << endl;
    t.Inorder(t.root);
    cout << endl;
    temp = t.Search(20);
    if (temp != NULL)
        cout << "Element " << temp->data << " is found" << endl;
    else
        cout << "Element not found in the given Bst" << endl;
    t.Delete(t.root, 50);
    cout << "In order" << endl;
    t.Inorder(t.root);
    cout << endl;
    return 0;
}