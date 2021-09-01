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
bool isSorted(struct Node *q)
{
    struct Node *p = first;
    int x = INT_MIN;
    while (p != NULL)
    {
        if (x > p->data)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}
int main()
{

    int A[] = {3, 5, 7, 10, 45, 20};
    create(A, 6);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    if (isSorted(first))
    {
        cout << "The linked list is in a sorted order" << endl;
    }
    else
    {
        cout << "The linked list is not sorted" << endl;
    }
    return 0;
}