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
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int find_middle(struct Node *s)
{
    struct Node *p = s;
    struct Node *q = s;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    return p->data;
}
int main()
{
    int arr[] = {20, 42, 51, 1, 20};
    create(arr, 5);
    Display(first);
    cout << "The middle element of the linked list is " << find_middle(first) << endl;
    return 0;
}