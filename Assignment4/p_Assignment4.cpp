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
        if(size == 0){
            cout<<"queue is empty";
            return;
        }

        cout<<"printing job: "<<array[fornt] << "printed successful"<<endl;

        fornt = (fornt+1)%n;
        size--;

        if(size==0){
            fornt = rear = -1;
        }
    }

    void display(){

    }
};