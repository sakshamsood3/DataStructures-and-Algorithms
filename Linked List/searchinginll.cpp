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
Node *search_ll(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
Node *search_ll_rec(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return search_ll_rec(p->next, key);
}
Node *search_ll_better(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int main()
{
    int A[] = {3, 5, 7, 45, 15, 20};
    create(A, 6);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    int key;
    cout << "Enter element to searched for in ll" << endl;
    cin >> key;
    if (search_ll_better(first, key) != NULL)
    {
        cout << "Element found that is " << search_ll_better(first, key)->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}