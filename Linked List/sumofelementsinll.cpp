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
void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int rec_sum(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return p->data + rec_sum(p->next);
}
int main()
{
    int A[] = {3, 5, 7, 10, 15, 20};
    create(A, 6);
    display(first);
    cout << endl;
    cout << sum(first) << endl;
    cout << rec_sum(first) << endl;
    return 0;
}