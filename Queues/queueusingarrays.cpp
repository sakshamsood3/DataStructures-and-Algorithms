#include <iostream>
using namespace std;
class Queue
{
    int size;
    int rear;
    int front;
    int *Q;

public:
    Queue()
    {
        size = 5;
        Q = new int[size];
        rear = front = -1;
    }
    Queue(int size)
    {
        this->size = size;
        Q = new int[size];
        front = rear = -1;
    }
    ~Queue()
    {
        delete[] Q;
    }
    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }
    void enqueue(int x)
    {
        if (isFull())
            cout << "Queue is Full" << endl;
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    int dequeue()
    {
        int x = -1;
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }
    void Display()
    {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            for (int i = front + 1; i <= rear; i++)
            {
                cout << Q[i] << " ";
            }
        }
    }
};
int main()
{
    int size;
    cout << "Enter the size of the Queue" << endl;
    cin >> size;
    Queue q(size);
    cout << q.isEmpty() << endl;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.isFull() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(70);
    q.Display();
    return 0;
}