#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL, *last = NULL;
void create(int arr[], int arr2[], int m, int n)
{
    struct Node *t1, *t2;
    struct Node *last1, *last2;
    first = new Node;
    second = new Node;
    first->data = arr[0];
    second->data = arr2[0];
    first->next = NULL;
    second->next = NULL;
    last1 = first;
    last2 = second;
    for (int i = 1; i < m; i++)
    {
        t1 = new Node;
        t1->data = arr[i];
        t1->next = NULL;
        last1->next = t1;
        last1 = t1;
    }
    for (int i = 1; i < n; i++)
    {
        t2 = new Node;
        t2->data = arr2[i];
        t2->next = NULL;
        last2->next = t2;
        last2 = t2;
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
void merge(struct Node *p, struct Node *q)
{
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if (p != NULL)
        {
            last->next = p;
        }
        else
        {
            last->next = q;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 5, 10, 12};
    int arr2[] = {3, 4, 7, 9, 11};
    create(arr, arr2, 5, 5);
    merge(first, second);
    display(third);
    return 0;
}