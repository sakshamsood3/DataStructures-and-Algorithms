#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} * head;
void create(int arr[], int n)
{
    struct Node *t, *last;
    head = new Node;
    head->data = arr[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head); //while loop doesnt work because head==p in first iteration itself
    cout << endl;
}
void Insert(int pos, int x)
{
    Node *t, *p;
    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }

            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    int arr[] = {2, 43, 45, 35, 1};
    create(arr, 5);
    Display(head); //we can use Display as well
    Insert(0, 66);
    Insert(3, 70);
    Display(head);
}