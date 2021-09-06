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
    first->prev = NULL;
    first->next = NULL;
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
void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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
int Delete(int index)
{
    if (index < 1 || index > Length(first))
        return -1;
    struct Node *p;
    int x;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
        if (first)
            first->prev = NULL;
    }
    else
    {
        struct Node *p = first;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}
int main()
{
    int arr[] = {20, 42, 51, 1, 20};
    create(arr, 5);
    Display(first);
    Delete(1);
    Delete(4);
    cout << "The linked list after inserting elements is " << endl;
    Display(first);
    return 0;
}