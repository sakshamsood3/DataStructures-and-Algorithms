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
void InsertNode(int pos, int element)
{
    struct Node *p, *t;
    if (pos == 0)
    {
        t = new Node;
        t->data = element;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; (i < pos - 1 && p); i++)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            t = new Node;
            t->data = element;
            t->next = p->next;
            p->next = t;
        }
    }
}
int main()
{
    int A[] = {3, 5, 7, 45, 15, 20};
    create(A, 6);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    cout << "Enter element to be inserted in Linked list and the position " << endl;
    int key, pos;
    cin >> key >> pos;
    InsertNode(pos, key);
    cout << "Linked list after insertion is " << endl;
    display(first);
}