#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;
void InsertLast(int element)
{
    Node *t = new Node;
    t->data = element;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
        last = t;
    }
    else
    {
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
int main()
{
    cout << "Enter number of elements of linked list" << endl;
    int n, ele;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element to be inserted" << endl;
        cin >> ele;
        InsertLast(ele);
    }
    cout << "Elements of the linked list are" << endl;
    display(first);
    return 0;
}