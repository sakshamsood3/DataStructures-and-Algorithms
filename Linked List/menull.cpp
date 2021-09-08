#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;
void create(int arr[], int n)
{
    struct Node *t;
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
    cout << endl;
}
void insert_beginning(int element)
{
    struct Node *t;
    t = new Node;
    t->data = element;
    t->next = first;
    first = t;
}
void insert_at_end(int element)
{
    struct Node *t;
    t = new Node;
    t->data = element;
    t->next = NULL;
    last->next = t;
    last = t;
}
int search(int element)
{
    struct Node *p = first;
    int cnt = 1;
    while (p != NULL)
    {
        if (p->data == element)
            return cnt;
        else
        {
            cnt++;
            p = p->next;
        }
    }
    return -1;
}
void insert_at_index(int element, char a, int key)
{
    struct Node *p = first, *t;
    int pos = search(key);
    if (a == 'b' || a == 'B')
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = element;
        t->next = p->next;
        p->next = t;
    }
    else if (a == 'a' || a == 'A')
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = element;
        t->next = p->next;
        p->next = t;
    }
}
int delete_beginning()
{
    int x;
    struct Node *p = first;
    first = first->next;
    x = p->data;
    delete p;
    return x;
}
int delete_at_index(int key)
{
    int x;
    struct Node *p = first, *q = NULL;
    int pos = search(key);
    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
    return x;
}
int delete_at_end()
{
    int x;
    struct Node *p = first, *q = NULL;
    while (p != last)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
    last = q;
    return x;
}

int main()
{
    int arr[] = {4, 6, 3, 42, 1};
    create(arr, 5);
    char choice = 'Y';
    do
    {
        int ch;
        cout << "Welcome to the linked list menu " << endl;
        cout << "1.Insertion at beginning " << endl;
        cout << "2.Insertion at end" << endl;
        cout << "3.Insertion after or before a specific node" << endl;
        cout << "4.Deletion from the beginning" << endl;
        cout << "5.Deletion from the end" << endl;
        cout << "6.Deletion of a specific node " << endl;
        cout << "7.Search for a node and display its position" << endl;
        cout << "8.Display all nodes" << endl;
        cout << "Enter the operation number" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int element;
            cout << "Enter the element you want to insert" << endl;
            cin >> element;
            insert_beginning(element);
            break;
        }
        case 2:
        {
            int element;
            cout << "Enter the element you want to insert" << endl;
            cin >> element;
            insert_at_end(element);
            break;
        }
        case 3:
        {
            int element, key;
            char c;
            cout << "Enter the element you want to insert" << endl;
            cin >> element;
            cout << "Enter the element of linked list you want to insert before/after" << endl;
            cin >> key;
            cout << "Enter b for before and a for after" << endl;
            cin >> c;
            insert_at_index(element, c, key);
            break;
        }
        case 4:
        {
            cout << "Element " << delete_beginning() << " deleted " << endl;
            break;
        }
        case 5:
        {
            cout << "Element " << delete_at_end() << " deleted" << endl;
            break;
        }
        case 6:
        {
            cout << "Enter element to be deleted from the linked list" << endl;
            int key;
            cin >> key;
            if (delete_at_index(key) != -1)
            {
                cout << "Element " << delete_at_index(key) << " deleted " << endl;
            }
            break;
        }
        case 7:
        {
            int element;
            cout << "Enter the element you want to search" << endl;
            cin >> element;
            if (search(element) != -1)
            {
                cout << " Element found at position " << search(element) << " from head" << endl;
            }
            else
            {
                cout << "Element not found" << endl;
            }
            break;
        }
        case 8:
        {
            cout << "Elements of the linked list are" << endl;
            display(first);
            break;
        }
        }
        cout << "Do you want to perform any more operations y/n?" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
