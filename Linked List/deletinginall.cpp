#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int arr[], int n)
{
    struct Node *t, *last;
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
void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int DeleteNode(int pos)
{
    struct Node *p = first, *q = NULL;
    int element;
    if (pos == 1)
    {
        first = first->next;
        element = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        element = p->data;
        delete p;
    }
    return element;
}
int main()
{

    int A[] = {3, 5, 7, 45, 15, 20};
    create(A, 6);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    cout << "Enter position of node to be deleted" << endl;
    int pos;
    cin >> pos;
    cout << "Element " << DeleteNode(pos) << " deleted from linked list" << endl;
    cout << "ELements of the linked list are" << endl;
    display(first);
    return 0;
}