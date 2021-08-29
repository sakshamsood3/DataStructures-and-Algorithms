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
int cnt_nodes(struct Node *p) //iterative
{
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}
int rec_count(struct Node *p) //recursive
{
    if (p == 0)
        return 0;
    else
        return 1 + rec_count(p->next);
}
int main()
{
    int A[] = {3, 5, 7, 10, 15, 20};
    create(A, 6);
    display(first);
    cout << endl;
    cout << rec_count(first);
    return 0;
}