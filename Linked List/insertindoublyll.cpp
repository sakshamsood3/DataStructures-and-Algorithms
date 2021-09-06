#include <iostream>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
void create(int arr[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Insert(int pos, int x)
{
    struct Node *t;

    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
    }
    else
    {
        struct Node *p = first;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        struct Node *t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int main()
{
    int arr[] = {20, 42, 51, 1, 20};
    create(arr, 5);
    Display(first);
    Insert(0, 50);
    Insert(6, 22);
    Insert(3, 21);
    cout << "The linked list after inserting elements is " << endl;
    Display(first);
}