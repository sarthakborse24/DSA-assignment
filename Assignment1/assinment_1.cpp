#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    float sgpa;

    void accept()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter SGPA: ";
        cin >> sgpa;
    }

    void display()
    {
        cout << roll << "\t" << name << "\t" << sgpa << endl;
    }
};

/* Bubble Sort : Roll No Ascending */
void bubbleSort(Student s[], int n)
{
    int i, j;
    Student temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

/* Insertion Sort : Alphabetical Order */
void insertionSort(Student s[], int n)
{
    int i, j;
    Student key;

    for (i = 1; i < n; i++)
    {
        key = s[i];
        j = i - 1;

        while (j >= 0 && s[j].name > key.name)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

/* Quick Sort : SGPA Descending */
int partition(Student s[], int low, int high)
{
    float pivot = s[high].sgpa;
    int i = low - 1;
    Student temp;

    for (int j = low; j < high; j++)
    {
        if (s[j].sgpa >= pivot)
        {
            i++;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    temp = s[i + 1];
    s[i + 1] = s[high];
    s[high] = temp;

    return i + 1;
}

void quickSort(Student s[], int low, int high)
{
    if (low < high)
    {
        int p = partition(s, low, high);
        quickSort(s, low, p - 1);

        quickSort(s, p + 1, high);
    }
}

/* Linear Search : SGPA */
void searchSGPA(Student s[], int n, float key)
{
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa == key)
        {
            s[i].display();
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "No student found with given SGPA" << endl;
    }
}

/* Binary Search : Roll No (Non Recursive) */
void binarySearch(Student s[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (s[mid].roll == key)
        {
            cout << "Student Found:" << endl;
            s[mid].display();
            return;
        }
        else if (s[mid].roll < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Student not found" << endl;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[20];

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        s[i].accept();
    }

    cout << "\nRoll Call List (Bubble Sort)\n";
    bubbleSort(s, n);
    for (int i = 0; i < n; i++)
        s[i].display();

    cout << "\nAlphabetical Order (Insertion Sort)\n";
    insertionSort(s, n);
    for (int i = 0; i < n; i++)
        s[i].display();

    cout << "\nTop 10 Toppers (Quick Sort)\n";
    quickSort(s, 0, n - 1);
    for (int i = 0; i < 10 && i < n; i++)
        s[i].display(); 

    float sg;
    cout << "\nEnter SGPA to search: ";
    cin >> sg;
    searchSGPA(s, n, sg);

    int r;
    cout << "\nEnter Roll No to search: ";
    cin >> r;

    bubbleSort(s, n);
    binarySearch(s, n, r);

    return 0;
}