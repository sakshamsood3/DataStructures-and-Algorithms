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
    void enqueue(int x)
    {
        if ((rear + 1) % size == front)
            cout << "Queue is Full" << endl;
        else
        {
            rear = (rear + 1) % size;
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
            front = (front + 1) % size;
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
            int i = front + 1;
            do
            {
                cout << Q[i] << " ";
                i = (i + 1) % size;
            } while (i != ((rear + 1) % size));
            cout << endl;
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
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(100);
    q.Display();
    return 0;
}