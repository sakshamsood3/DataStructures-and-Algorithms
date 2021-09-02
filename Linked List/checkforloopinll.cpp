#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int arr[], int n)
{
    struct Node *t;
    struct Node *last;
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
bool isLoop(struct Node *s)
{
    struct Node *p;
    struct Node *q;
    p = s;
    q = s;
    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
        }
    } while (p && q && (p != q));
    if (p == q)
        return true;
    else
        return false;
}
void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    int A[] = {3, 5, 7, 10, 15, 20};
    create(A, 6);
    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    if (isLoop(first))
    {
        cout << "Linked list has a loop";
    }
    else
    {
        cout << "no loop present in the linked list";
    }
    return 0;
}