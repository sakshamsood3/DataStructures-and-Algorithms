#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int arr[], int n)
    {
        Node *t, *last;
        first = new Node;
        first->data = arr[0];
        first->next = NULL;
        last = first;
        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = arr[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    ~LinkedList()
    {
        Node *p = first;
        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }
    void Display()
    {
        Node *p = first;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    int Length()
    {
        Node *p = first;
        int cnt = 0;
        while (p)
        {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    void Insert(int index, int x)
    {
        Node *t, *p = first;
        t = new Node;
        t->data = x;
        t->next = NULL;
        if (index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    int Delete(int index)
    {
        Node *q = NULL, *p = first;
        int x = -1;
        if (index == 1)
        {
            first = first->next;
            x = p->data;
            delete p;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
        }
        return x;
    }
};
int main()
{
    int arr[] = {5, 10, 20, 30, 50};
    LinkedList l(arr, 5);
    l.Display();
    cout << l.Length() << endl;
    l.Insert(0, 1);
    l.Insert(3, 25);
    l.Display();
    cout << l.Delete(3) << endl;
    l.Display();
    return 0;
}