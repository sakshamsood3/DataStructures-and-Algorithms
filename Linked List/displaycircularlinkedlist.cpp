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
void RecursiveDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        Display(p->next);
    }
    flag = 0;
}
int main()
{
    int arr[] = {2, 43, 45, 35, 1};
    create(arr, 5);
    RecursiveDisplay(head); //we can use Display as well
}