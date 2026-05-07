#include <iostream>
using namespace std;

#define n 5

class queue
{
public:
    int front, rear, size;
    string array[n];

    // Constructor
    queue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    // Add Print Job
    void enqueue(string job)
    {
        if (size == n)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % n;
        array[rear] = job;
        size++;

        cout << "Print Job Added Successfully\n";
    }

    // Process Print Job
    void dequeue()
    {
        if (size == 0)
        {
            cout << "No Print Jobs in Queue\n";
            return;
        }

        cout << "Printing Job: " << array[front] << endl;
        cout << "Job Printed Successfully\n";

        front = (front + 1) % n;
        size--;

        if (size == 0)
        {
            front = rear = -1;
        }
    }

    // Display Print Jobs
    void display()
    {
        if (size == 0)
        {
            cout << "No Print Jobs in Queue\n";
            return;
        }

        cout << "Print Jobs in Queue:\n";

        int i = front;
        int count = 1;

        while (true)
        {
            cout << count++ << ". " << array[i] << endl;

            if (i == rear)
                break;

            i = (i + 1) % n;
        }
    }
};

int main()
{
    queue q;
    int choice;
    string job;

    do
    {
        cout << "\n------ Printer Spooling System ------\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Print Job\n";
        cout << "3. Display Print Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Print Job Name: ";
            cin >> job;
            q.enqueue(job);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}