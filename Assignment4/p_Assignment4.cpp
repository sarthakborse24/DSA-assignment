#include <iostream>
using namespace std;

#define n 10

class queue
{
public:
    int front, rear, size;
    string array[n];

    queue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(string job)
    {

        if (size == n)
        {
            cout << "queue is full!!";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % n;
        array[rear] = job;
        size++;

        cout << "job added";
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "queue is empty";
            return;
        }

        cout << "printing job: " << array[front] << "printed successful" << endl;

        front = (front + 1) % n;
        size--;

        if (size == 0)
        {
            front = rear = -1;
        }
    }

    void display()
    {
        if (size == 0)
        {
            cout << "no jobs";
            return;
        }
        int i = front;
        int count = 1;

        while (true)
        {
            cout << count++ << ". " << array[i] << endl;
            if (i == rear)
            {
                break;
            }

            i = (i + 1) % n;
        }
    }
};