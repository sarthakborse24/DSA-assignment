#include<iostream>
#include<string>
using namespace std;

#define SIZE 10

class HashTable
{
    string user[SIZE];
    int pass[SIZE];
    int link[SIZE];

public:

    HashTable()
    {
        for(int i=0;i<SIZE;i++)
        {
            user[i] = "";
            pass[i] = -1;
            link[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    int isDuplicate(string uid)
    {
        for(int i=0;i<SIZE;i++)
        {
            if(user[i] == uid)
                return 1;
        }
        return 0;
    }

    int isFull()
    {
        for(int i=0;i<SIZE;i++)
        {
            if(user[i] == "")
                return 0;
        }
        return 1;
    }

    void display()
    {
        cout<<"\nIndex\tUsername\tLink\n";
        cout<<"----------------------------------------\n";
        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<"\t";
            if(user[i] == "")
                cout<<"-\t\t";
            else
                cout<<user[i]<<"\t\t";
            cout<<link[i]<<"\n";
        }
    }

    void linearWithoutReplacement(string uid,int pwd)
    {
        if(isDuplicate(uid))
        {
            cout<<"Duplicate User ID\n";
            return;
        }

        if(isFull())
        {
            cout<<"Hash Table Full\n";
            return;
        }

        int index = hashFunction(pwd);

        if(user[index] == "")
        {
            user[index] = uid;
            pass[index] = pwd;
        }
        else
        {
            cout<<"Collision occurred at index "<<index<<"\n";
            int i = (index + 1) % SIZE;
            while(i != index)
            {
                if(user[i] == "")
                {
                    user[i] = uid;
                    pass[i] = pwd;
                    return;
                }
                i = (i + 1) % SIZE;
            }
            cout<<"Hash Table Full\n";
        }
    }

    void linearWithReplacement(string uid,int pwd)
    {
        if(isDuplicate(uid))
        {
            cout<<"Duplicate User ID\n";
            return;
        }

        if(isFull())
        {
            cout<<"Hash Table Full\n";
            return;
        }

        int index = hashFunction(pwd);

        if(user[index] == "")
        {
            user[index] = uid;
            pass[index] = pwd;
        }
        else
        {
            cout<<"Collision occurred at index "<<index<<"\n";

            int existingHash = hashFunction(pass[index]);

            if(existingHash != index)
            {
                string tempUser = user[index];
                int tempPass = pass[index];

                user[index] = uid;
                pass[index] = pwd;

                int i = (index + 1) % SIZE;
                while(user[i] != "")
                    i = (i + 1) % SIZE;

                user[i] = tempUser;
                pass[i] = tempPass;
            }
            else
            {
                int i = (index + 1) % SIZE;
                while(user[i] != "")
                    i = (i + 1) % SIZE;

                user[i] = uid;
                pass[i] = pwd;
            }
        }
    }

    void chainingWithoutReplacement(string uid, int pwd)
{
    if(isFull())
    {
        cout << "Hash Table Full\n";
        return;
    }

    if(isDuplicate(uid))
    {
        cout << "Duplicate User ID\n";
        return;
    }

    int index = hashFunction(pwd);

    // If slot is empty
    if(user[index] == "")
    {
        user[index] = uid;
        pass[index] = pwd;
    }
    else
    {
        cout << "Collision occurred at index " << index << endl;

        // Linear probing to find empty slot
        int i = (index + 1) % SIZE;

        while(user[i] != "")
        {
            i = (i + 1) % SIZE;
        }

        user[i] = uid;
        pass[i] = pwd;

        // Update chain only if original element belongs to same hash index
        if(hashFunction(pass[index]) == index)
        {
            int temp = index;

            while(link[temp] != -1)
            {
                temp = link[temp];
            }

            link[temp] = i;
        }
    }
}

   void chainingWithReplacement(string uid, int pwd)
{
    if(isFull())
    {
        cout << "Hash Table Full\n";
        return;
    }

    if(isDuplicate(uid))
    {
        cout << "Duplicate User ID\n";
        return;
    }

    int index = hashFunction(pwd);

    // If home position is empty
    if(user[index] == "")
    {
        user[index] = uid;
        pass[index] = pwd;
    }
    else
    {
        cout << "Collision occurred at index " << index << endl;

        int existingHash = hashFunction(pass[index]);

        // Replacement condition
        if(existingHash != index)
        {
            // Store old record
            string tempUser = user[index];
            int tempPass = pass[index];
            int tempLink = link[index];

            // Replace with new record
            user[index] = uid;
            pass[index] = pwd;
            link[index] = -1;

            // Find new place for old record using linear probing
            int i = (index + 1) % SIZE;

            while(user[i] != "")
            {
                i = (i + 1) % SIZE;
            }

            user[i] = tempUser;
            pass[i] = tempPass;
            link[i] = tempLink;

            // Fix chain of displaced record
            int head = existingHash;

            if(head != index)
            {
                int prev = head;

                while(link[prev] != index)
                {
                    prev = link[prev];
                }

                link[prev] = i;
            }
        }
        else
        {
            // Insert normally at next free slot
            int i = (index + 1) % SIZE;

            while(user[i] != "")
            {
                i = (i + 1) % SIZE;
            }

            user[i] = uid;
            pass[i] = pwd;

            // Update chain
            int temp = index;

            while(link[temp] != -1)
            {
                temp = link[temp];
            }

            link[temp] = i;
        }
    }
}
};

int main()
{
    HashTable h;
    int choice,n;
    string uid;
    int pwd;

    cout<<"1. Linear Without Replacement\n";
    cout<<"2. Linear With Replacement\n";
    cout<<"3. Chaining Without Replacement\n";
    cout<<"4. Chaining With Replacement\n";

    cout<<"Enter choice: ";
    cin>>choice;

    cout<<"Enter number of users: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter User ID: ";
        cin>>uid;
        cout<<"Enter Password: ";
        cin>>pwd;

        if(choice==1)
            h.linearWithoutReplacement(uid,pwd);
        else if(choice==2)
            h.linearWithReplacement(uid,pwd);
        else if(choice==3)
            h.chainingWithoutReplacement(uid,pwd);
        else if(choice==4)
            h.chainingWithReplacement(uid,pwd);
    }

    h.display();

    return 0;
}