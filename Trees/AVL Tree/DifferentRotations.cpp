#include <iostream>
using namespace std;
class Node
{
public:
    Node *lchild;
    Node *rchild;
    int data;
    int height;
};
class AVL
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
    int NodeHeight(Node *p)
    {
        int hl, hr;
        hl = p && p->lchild ? p->lchild->height : 0;
        hr = p && p->rchild ? p->rchild->height : 0;
        return hl > hr ? hl + 1 : hr + 1;
    }
    int BalanceFactor(Node *p)
    {
        int hl, hr;
        hl = p && p->lchild ? p->lchild->height : 0;
        hr = p && p->rchild ? p->rchild->height : 0;
        return hl - hr;
    }
    Node *LLRotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;
        pl->rchild = p;
        p->lchild = plr;
        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);
        if (root == p)
        {
            root = pl;
        }
        return pl;
    }
    Node *LRRotation(Node *p)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;
        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;
        plr->lchild = pl;
        plr->rchild = p;
        pl->height = NodeHeight(pl);
        p->height = NodeHeight(p);
        plr->height = NodeHeight(plr);
        if (p == root)
        {
            root = plr;
        }
        return plr;
    }
    Node *RRRotation(Node *p)
    {
        Node *pr = p->rchild;
        p->rchild = pr->lchild;
        pr->lchild = p;
        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        if (p == root)
            root = pr;
        return pr;
    }
    Node *RLRotation(Node *p)
    {
        Node *pr = p->rchild;
        Node *prl = pr->lchild;
        p->rchild = prl->lchild;
        pr->lchild = prl->rchild;
        prl->rchild = pr;
        prl->lchild = p;
        pr->height = NodeHeight(pr);
        p->height = NodeHeight(p);
        prl->height = NodeHeight(prl);
        if (p == root)
            root = prl;
        return prl;
    }
    Node *RInsert(Node *p, int key)
    {
        Node *t;
        if (p == NULL)
        {
            t = new Node;
            t->data = key;
            t->height = 1;
            t->lchild = t->rchild = NULL;
            return t;
        }
        if (key < p->data)
            p->lchild = RInsert(p->lchild, key);
        else if (key > p->data)
            p->rchild = RInsert(p->rchild, key);
        p->height = NodeHeight(p);
        if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
            return LLRotation(p);
        else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
            return LRRotation(p);
        else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
            return RRRotation(p);
        else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
            return RLRotation(p);
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
    AVL t;
    t.root = t.RInsert(t.root, 10);
    t.RInsert(t.root, 30);
    t.RInsert(t.root, 20);
    cout << "In order" << endl;
    t.Inorder(t.root);
    return 0;
}