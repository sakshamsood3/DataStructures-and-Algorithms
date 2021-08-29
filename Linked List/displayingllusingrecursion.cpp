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
void recursive_display(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        recursive_display(p->next);
    }
}
void revrecursive_display(struct Node *p) //to print in reverse order
{
    if (p != NULL)
    {
        recursive_display(p->next);
        cout << p->data << " ";
    }
}
int main()
{
    int arr[] = {2, 53, 5, 1, 22};
    create(arr, 5);
    cout << "Displaying elements of linked list" << endl;
    recursive_display(first);
    cout << endl;
    cout << "Displaying elements of linked list in reverse order" << endl;
    revrecursive_display(first);
    return 0;
}