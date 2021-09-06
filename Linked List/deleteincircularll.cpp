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
int Length(struct Node *p)
{
    int cnt = 0;
    do
    {
        cnt++;
        p = p->next;
    } while (p != head);
    return cnt;
}
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x;
    if (index < 0 || index > Length(head))
    {
        return -1;
    }
    if (index == 0)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        p = head;
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int arr[] = {2, 43, 45, 35, 1};
    create(arr, 5);
    Display(head);
    cout << Delete(head, 0) << endl;
    cout << Delete(head, 3) << endl;
    Display(head);
}