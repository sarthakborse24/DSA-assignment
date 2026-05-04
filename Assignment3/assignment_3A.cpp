#include <iostream>
using namespace std;
class Song
{
public:
    int id;
    string name;
    string artist_name;
    int duration;
    Song *next;
    Song(int val, string sname, string sartist_name, int sduration)
    {
        id = val;
        name = sname;
        artist_name = sartist_name;
        duration = sduration;
        next = nullptr;
    }
};
class playlist
{
public:
    Song *head = nullptr;
    void addsong(int val, string sname, string sartist_name, int sduration)
    {
        Song *newsong = new Song(val, sname, sartist_name, sduration);

        Song *temp = head;
        if (head == nullptr)
        {
            head = newsong;
            return;
        }
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newsong;
    }
    void deletesong(int val)
    {
        Song *temp = head;
        if (head == nullptr)
        {
            cout << "empty play list...";
            return;
        }
        if (head->id == val)
        {
            Song *todelete = head;
            head = head->next;
            delete todelete;
            return;
        }
        while (temp->next != nullptr && temp->next->id != val)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {

            cout << "Song not found\n";
            return;
        }
        Song *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        return;
    }
    void Display()
    {
        Song *temp = head;
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }
        while (temp != nullptr)
        {
            cout << temp->id << "|" << temp->name << "|" << temp->artist_name << "|" << temp->duration << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    int choice;
    int id, duration;
    string name, artist_name;
    playlist p1;
    while (true)
    {
        cout << "\n1. Add song" << endl;

        cout << "2. Display songs playlist" << endl;
        cout << "3. Delete song by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Song Name: ";
            getline(cin, name);
            cout << "Enter Artist Name: ";
            getline(cin, artist_name);
            cout << "Enter Duration: ";
            cin >> duration;
            p1.addsong(id, name, artist_name, duration);
            break;
        case 2:
            p1.Display();
            break;
        case 3:
            cin >> id;
            p1.deletesong(id);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}