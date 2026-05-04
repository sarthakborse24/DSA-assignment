#include <iostream>
using namespace std;
#define size 10

class Hashtable
{
    string user[size];
    int pass[size];

public:
    Hashtable()
    {
        for (int i = 0; i < size; i++)
        {
            user[i] = "";
            pass[i] = -1;
        }
    }

    int hashfunction(int key)
    {
        return key % size;
    }

    int isduplicate(string uid)
    {
        for (int i = 0; i < size; i++)
        {
            if (user[i] == uid)
            {
                return 1;
            }
            return 0;
        }
    }
    int isfull()
    {
        for (int i = 0; i < size; i++)
        {
            if (user[i] == "")
            {
                return 0;
            }
            return 1;
        }
    }
    void display()
    {
        cout<<"\nIndex\tUsername\tPassword\n";
        cout<<"----------------------------------------\n";
        for(int i=0;i<size;i++)
        {
            cout<<i<<"\t";
            if(user[i] == "")
                cout<<"-\t\t";
            else
                cout<<user[i]<<"\t\t";
                cout<<pass[i]<<"\n";
        }
    }

    void linerwithout(string uid,int pwd){

        if(isfull()){
            cout<<"Hash table is full";
            return;
        }
        if(isduplicate(uid)){
            cout<<"duplicate user";
            return;
        }

        int index = hashfunction(pwd);

        if(user[index]==""){
            user[index]=uid;
            pass[index]=pwd;
        }
        else{
            cout<<"collision at index "<< index ;
            int i = (index+1)%size;
            while (i != index)
            {
                if(user[i] == ""){
                    user[i]=uid;
                    pass[i]=pwd;
                    return;
                }
                i = (i+1)%size;
            }
            
        }
    }

    void linerwithreplacement(string uid, int pwd){
        if(isfull()){
            cout<<"Hash table is full";
            return;
        }
        if(isduplicate(uid)){
            cout<<"duplicate user";
            return;
        }

        int index = hashfunction(pwd);

        if(user[index]==""){
            user[index]=uid;
            pass[index]=pwd;
        }
        else{
            cout<<"collision at index: "<<index;
            int cindex = hashfunction(pass[index]);

            if(cindex != index){

                string tempuser = user[index];
                int temppass = pass[index];

                user[index] = uid;
                pass[index] = pwd;

                int i = (index+1)%size;
                while(user[i]!=""){
                    i = (index+1)%size;
                }
                user[i]=tempuser;
                pass[i]=temppass;
            }
            else{
                int i = (index+1)%size;
                while(user[i]!=""){
                    i = (index+1)%size;
                }
                user[i]=uid;
                pass[i]=pwd;
            }
        }
    }
};
int main()
{
    Hashtable t;
    int n , pwd;
    string uid;
    
    cout<<"enter number of user: ";
    cin>> n;

    for(int i=0 ;i<n;i++){
        cout<<"enter username: ";
        cin>>uid;
        cout<<"enter password: ";
        cin>>pwd;

        t.linerwithout(uid,pwd);
    }
    t.display();
}