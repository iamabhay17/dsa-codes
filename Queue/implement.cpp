// implementing queue class in cpp

#include <iostream>
using namespace std;

class Queue
{
public:
    int size, currSize;
    int front, rear;
    int *arr;

    Queue(int n)
    {
        this->size = n;
        this->currSize = 0;
        this->arr = new int[n];
        this->front = -1;
        this->rear = -1;
    }

    void enque(int n)
    {
        if (rear == size - 1)
        {
            cout << "cannot enque. size full\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear += 1;
        arr[rear] = n;
        cout << "ELement added : " << n << endl;
    }

    void deque()
    {
        if (front == -1)
        {
            cout << "cannot deque. empty queue\n";
            return;
        }
        cout << "ELement removed : " << arr[front] << endl;
        front = front + 1;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue one(5);
    one.deque();
    one.enque(1);
    one.enque(1);
    one.enque(1);
    one.enque(1);
    one.enque(1);
    one.enque(1);
    one.deque();
    one.display();
    return 0;
}