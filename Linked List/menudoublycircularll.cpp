#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyCircularLinkedList
{
    Node *head;

public:
    DoublyCircularLinkedList()
    {
        head = NULL;
    }
    void InsertatHead(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t->prev = t;
        if (head == NULL)
            head = t;
        else
        {
            t->next = head;
            t->prev = head->prev;
            head->prev = t;
            t->prev->next = t;
            head = t;
        }
    }
    void InsertatLast(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->next = t->prev = t;
        if (head == NULL)
            head = t;
        else
        {
            t->next = head;
            t->prev = head->prev;
            head->prev->next = t;
            head->prev = t;
        }
    }
    void InsertatPosition(int d, int key)
    {
        if (head == NULL)
            cout << "The list is empty" << endl;
        else
        {
            Node *p = head;
            while (p->next != head && p->data != key)
                p = p->next;
            if (p->data != key)
                cout << "element not found" << endl;
            else
            {
                Node *t = new Node;
                t->data = d;
                t->next = p->next;
                t->prev = p;
                p->next = t;
                t->next->prev = t;
            }
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
            while (p->next != head && p->data != ele)
            {
                i++;
                p = p->next;
            }
            if (p->data != ele)
                cout << "Element not found" << endl;
            else
                cout << "Element found at position " << i << endl;
        }
    }
    void DeleteHead()
    {
        if (head == NULL)
            cout << "Deletion not possible" << endl;
        else
        {
            Node *t = head;
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
            }
            delete t;
        }
    }
    void DeleteLast()
    {
        if (head == NULL)
            cout << "list is empty" << endl;
        else
        {
            Node *temp = head;
            if (temp->next == temp)
                head = NULL;
            else
            {
                temp = temp->prev;
                head->prev = temp->prev;
                head->prev->next = head;
            }
            delete temp;
        }
    }
    void DeleteatPosition(int x)
    {
        if (head == NULL)
            cout << "list  is empty" << endl;
        else
        {
            Node *temp = head;
            while (temp->next != head && temp->data != x)
                temp = temp->next;
            if (temp->data != x)
            {
                cout << "Element not found cant be deleted" << endl;
            }
            else if (temp->next == temp)
            {
                head = NULL;
                delete temp;
            }
            else
            {

                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                if (temp == head)
                    head = head->next;
                delete temp;
            }
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
};
int main()
{
    cout << "Welcome to a menu driven program for Doubly Circular linked list" << endl;
    DoublyCircularLinkedList ll;
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