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
void Remove_Duplicates(struct Node *t)
{
    struct Node *p = first;
    struct Node *q = first->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
int main()
{

    int A[] = {1, 2, 3, 3, 3, 4, 4, 5};
    create(A, 8);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    Remove_Duplicates(first);
    cout << "ELements of the linked list after removing duplicates are" << endl;
    display(first);
    cout << endl;
    return 0;
}