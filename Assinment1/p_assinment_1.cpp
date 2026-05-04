#include <iostream>
using namespace std;

class student{
    public:
    int roll;
    string name;
    float cgpa;

    void detail(){
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter SGPA: ";
        cin >> cgpa;
    }

    void display()
    {
        cout << roll << "\t" << name << "\t" << cgpa << endl;
    }
};
// sort by roll no. in asending order
void bubblesort(student s[],int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-i-1;j++){
            if(s[j].roll>s[j+1].roll){
                swap(s[j],s[j+1]);
            }
        }
    }
}

// sort by name in alpha order
void insertionsort(student s[] , int n){
    for(int i=1;i<n;i++){
        student curr = s[i];
        int prv = i-1;

        while (prv >= 0 && s[prv].name>curr.name)
        {
            s[prv+1] = s[prv];
            prv--;
        }
        s[prv+1] = curr;
    }
} 

// quick sort 
int partition(student s[],int start, int end){
    int i = start -1;
    int pivot = s[end].cgpa;

    for(int j=start ; j<end;j++){
        if(s[j].cgpa >= pivot){
            i++;
            swap(s[i],s[j]);
        }
    }
    swap(s[end],s[i+1]);

    return i+1;
}

void quicksort(student s[], int start, int end){
    if(start < end){   // ✅ base condition
        int pi = partition(s,start,end);
        quicksort(s,start,pi-1);
        quicksort(s,pi+1,end);
    }
}


int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    student s[20];

    for(int i=0; i<n ; i++){
        s[i].detail();
    }

    cout << "\nRoll Call List (Bubble Sort)\n";
    bubblesort(s, n);
    for (int i = 0; i < n; i++)
        s[i].display();
    
    cout << "\nAlphabetical Order (Insertion Sort)\n";
    insertionsort(s, n);
    for (int i = 0; i < n; i++)
        s[i].display();

    cout << "\nTop 10 Toppers (Quick Sort)\n";
    quicksort(s, 0, n - 1);
    for (int i = 0; i < 10 && i < n; i++)
        s[i].display();     
}