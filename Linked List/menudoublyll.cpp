#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }
    void AddNode(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t->prev = NULL;
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            head->prev = NULL;
            Node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
            t->prev = p;
        }
    }
    void Display()
    {
        cout << "Displaying the linked list" << endl;
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void InsertatHead(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t->prev = NULL;
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            head->prev = t;
            t->next = head;
            head = t;
        }
    }
    void InsertatLast(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t->prev = NULL;
        if (head == NULL)
        {
            head = t;
        }
        else
        {
            Node *p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = t;
            t->prev = p;
        }
    }
    void InsertatPosition(int d, int key)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t->prev = NULL;
        Node *p = head;
        while (p && p->data != key)
            p = p->next;
        if (p == NULL)
            cout << "Insertion not possible" << endl;
        else if (p->next == NULL)
        {
            InsertatLast(d);
        }
        else
        {
            t->next = p->next;
            t->prev = p;
            p->next->prev = t;
            p->next = t;
        }
    }
    void Search(int ele)
    {
        Node *p = head;
        if (p == NULL)
            cout << "Linked list is empty" << endl;
        else
        {
            int i = 1;
            while (p && p->data != ele)
            {
                i++;
                p = p->next;
            }
            if (p == NULL)
                cout << "Element not found" << endl;
            else
                cout << "Element found at position " << i << endl;
        }
    }
    void DeleteatHead()
    {
        Node *p = head;
        if (p == NULL)
            cout << "cannot delete list is empty" << endl;
        else
        {
            head = head->next;
            head->prev = NULL;
            delete p;
        }
    }
    void DeleteLast()
    {
        Node *p = head;
        Node *pre = NULL;
        while (p->next != NULL)
        {
            pre = p;
            p = p->next;
        }
        pre->next = NULL;
        p->prev = NULL;
        delete p;
    }
    void DeleteAtPosition(int ele)
    {
        Node *p = head, *pre = NULL;
        if (head == NULL)
            cout << "Cant delete the list is empty" << endl;
        else
        {
            while (p && p->data != ele)
            {
                pre = p;
                p = p->next;
            }
            if (p == NULL)
                cout << "cant delete element not found" << endl;
            else if (p == head)
            {
                DeleteatHead();
            }
            else if (p->next == NULL)
            {
                DeleteLast();
            }
            else
            {
                pre->next = p->next;
                p->next->prev = pre;
                delete p;
            }
        }
    }
};

int main()
{
    cout << "Welcome to a menu driven program for doubly linked list" << endl;
    DoublyLinkedList ll;
    char choice = 'y';
    do
    {
        cout << "1.Add a Node" << endl;
        cout << "2.Display the linked list" << endl;
        cout << "3.Insert at head" << endl;
        cout << "4.Insert at last" << endl;
        cout << "5. Insert after a particular element" << endl;
        cout << "6.Delete at head" << endl;
        cout << "7.delete at last" << endl;
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
            ll.AddNode(ele);
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
            ll.DeleteatHead();
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
            ll.DeleteAtPosition(ele);
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