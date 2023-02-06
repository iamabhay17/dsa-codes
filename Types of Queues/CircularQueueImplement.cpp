// implementing circular queue

#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int size;
    int front, rear;
    int *arr;

    Queue(int n)
    {
        this->size = n;
        this->arr = new int[n];
        this->front = -1;
        this->rear = -1;
    }

    void enque(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear = (front - 1) % size - 1))
        {
            cout << "cannot enque. size full\n";
            return;
        }
        else if (front == -1) /* Insert First Element */
        {
            front = rear = 0;
            arr[rear] = value;
        }

        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }

        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    void deque()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty";
            return;
        }

        int data = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (front == size - 1)
            front = 0;

        else
            front++;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty";
            return;
        }

        cout << "\nElements in Circular Queue are: ";

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }

        else
        {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
    }
};
int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);

    // Display elements present in Circular Queue
    q.display();

    // Deleting elements from Circular Queue
    q.deque();

    q.display();

    q.enque(50);
    q.enque(60);
    q.enque(70);

    q.display();

    return 0;
}