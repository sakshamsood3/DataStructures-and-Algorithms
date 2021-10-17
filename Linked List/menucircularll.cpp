#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    void InsertatLast(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t;
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            t->next = head;
            struct Node *p;
            p = head;
            while (p->next != head)
                p = p->next;
            p->next = t;
        }
    }
    void InsertatHead(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t;
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            t->next = head;
            Node *p = head;
            while (p->next != head)
                p = p->next;
            p->next = t;
            head = t;
        }
    }
    void Display()
    {
        Node *p = head;
        cout << "Displaying the linked list" << endl;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
    void Search(int x)
    {
        int i = 1;
        if (head == NULL)
            cout << "the list is empty" << endl;
        else
        {
            Node *t = head;
            while (t->next != head && t->data != x)
            {
                i++;
                t = t->next;
            }
            if (t->data == x)
                cout << "Element found at position " << i << endl;
            else
                cout << "element not found" << endl;
        }
    }
    void InsertatPosition(int d, int x)
    {
        if (head == NULL)
            cout << "The linked list is empty" << endl;
        else
        {
            Node *p = head;
            while (p->next != head && p->data != x)
                p = p->next;
            if (p->data == x)
            {
                Node *t = new Node;
                t->data = d;
                t->next = p->next;
                p->next = t;
            }
            else
            {
                cout << "Insertion not possible" << endl;
            }
        }
    }
    void DeleteHead()
    {
        if (head == NULL)
            cout << "cant delete because the list is empty" << endl;
        else
        {
            Node *p = head, *q = head;
            while (p->next != head)
                p = p->next;
            if (p == head)
            {
                head = NULL;
            }
            else
            {
                p->next = q->next;
                head = head->next;
                delete q;
            }
        }
    }
    void DeleteLast()
    {
        if (head == NULL)
            cout << "cant delete the element because list is empty" << endl;
        else
        {
            Node *p = head, *q = NULL;
            while (p->next != head)
            {
                q = p;
                p = p->next;
            }
            if (p == head)
            {
                head = NULL;
            }
            else
            {
                q->next = p->next;
                delete p;
            }
        }
    }
    void DeleteatPosition(int x)
    {
        Node *p = head, *q = NULL;
        if (head == NULL)
            cout << "cant delete the element because list is empty" << endl;
        while (p->next != head && p->data != x)
        {
            q = p;
            p = p->next;
        }
        if (p == head)
        {
            DeleteHead();
        }
        else if (p->next == head)
        {
            DeleteLast();
        }
        else
        {
            q->next = p->next;
            delete p;
        }
    }
};
int main()
{
    cout << "Welcome to a menu driven program for Circular linked list" << endl;
    CircularLinkedList ll;
    char choice = 'y';
    do
    {
        cout << "1.Add a Node" << endl;
        cout << "2.Display the linked list" << endl;
        cout << "3.Insert at head" << endl;
        cout << "4.Insert at last" << endl;
        cout << "5. Insert after a particular element" << endl;
        cout << "6.Delete at head" << endl;
        cout << "7.Delete at last" << endl;
        cout << "8. Delete a particular element" << endl;
        cout << "9. Search for an element" << endl;
        int ch;
        cout << "Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int ele;
            cout << "enter element to be added" << endl;
            cin >> ele;
            ll.InsertatLast(ele);
            ll.Display();
            break;
        }
        case 2:
        {
            ll.Display();
            break;
        }
        case 3:
        {
            int ele;
            cout << "enter element to be inserted" << endl;
            cin >> ele;
            ll.InsertatHead(ele);
            ll.Display();
            break;
        }
        case 4:
        {
            int ele;
            cout << "enter element to be inserted" << endl;
            cin >> ele;
            ll.InsertatLast(ele);
            ll.Display();
            break;
        }
        case 5:
        {
            int ele, key;
            cout << "enter element to be inserted" << endl;
            cin >> ele;
            cout << "Element after which it is to be inserted" << endl;
            cin >> key;
            ll.InsertatPosition(ele, key);
            ll.Display();
            break;
        }
        case 6:
        {
            ll.DeleteHead();
            ll.Display();
            break;
        }
        case 7:
        {
            ll.DeleteLast();
            ll.Display();
            break;
        }
        case 8:
        {
            int ele;
            cout << "Enter the element to be deleted" << endl;
            cin >> ele;
            ll.DeleteatPosition(ele);
            ll.Display();
            break;
        }
        case 9:
        {
            int ele;
            cout << "enter element to be searched for" << endl;
            cin >> ele;
            ll.Search(ele);
            break;
        }
        }
        cout << "Do you want to perform more operations ? enter y/n" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}