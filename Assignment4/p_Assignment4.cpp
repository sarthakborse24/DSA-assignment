#include <iostream>
using namespace std;

#define n 10

class queue
{
public:
    int fornt, rear, size;
    string array[n];

    queue()
    {
        fornt = -1;
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
        if (fornt == -1)
        {
            fornt = 0;
        }

        rear = (rear + 1) % n;
        array[rear] = job;
        size++;

        cout << "job added";
    }

    void dequeue()
    {
        
    }

    void display(){

    }
};