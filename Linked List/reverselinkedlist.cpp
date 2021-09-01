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
void reverse_elements(struct Node *t) //not preferrable for complex data types
{
    int arr[6]; //array of size of nodes;
    struct Node *p = first;
    int i = 0;
    while (p != NULL)
    {
        arr[i] = p->data;
        p = p->next;
        i++;
    }
    i--;
    p = first;
    while (p != NULL)
    {
        p->data = arr[i];
        p = p->next;
        i--;
    }
}
void reverse_links(struct Node *t)
{
    struct Node *p = first, *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void recursive_reverse(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        recursive_reverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{

    int A[] = {1, 4, 45, 20, 15, 10};
    create(A, 6);
    cout << "ELements of the linked list are" << endl;
    display(first);
    cout << endl;
    recursive_reverse(NULL, first);
    //reverse_links(first);
    //reverse_elements(first);  //both of these can work as well
    cout << "ELements of the linked list after reversing are" << endl;
    display(first);
    cout << endl;
    return 0;
}