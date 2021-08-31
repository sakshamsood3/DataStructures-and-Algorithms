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
int max_element(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int max_element_rec(struct Node *p)
{
    if (p == NULL)
        return INT_MIN;
    else
    {
        int x = 0;
        x = max_element_rec(p->next);
        return x > p->data ? x : p->data;
    }
}
int main()
{
    int A[] = {3, 5, 7, 45, 15, 20};
    create(A, 6);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    cout << "Max element in the linked list is " << max_element_rec(first) << endl; // we can use max_element func as well
}