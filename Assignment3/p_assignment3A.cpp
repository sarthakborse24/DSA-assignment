#include <iostream>
using namespace std;

class Song{
public:
    int id;
    string name;
    string artist_name;
    int duration;
    Song *next;

    Song(int val , string sname , string sartist_name , int sduration){
        id = val;
        name = sname;
        artist_name = sartist_name;
        duration = sduration;
        next = nullptr;
    }
};

class playlist{
public:
    Song * head = nullptr;

    void addsong(int id , string name , string artist_name , int duration){
        Song *newsong = new Song(id,name,artist_name,duration);
        if(head== nullptr){
            head = newsong;
            return;
        }

        Song *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next= newsong;
    }
    void deletesong(int val){
        if(head == nullptr){
            cout<<"there is no song in play list";
            return;
        }
        Song *temp = head;
        if(head->id == val){
            Song *todelete = head;
            head = head->next;

            delete todelete;

        }
        while (temp->next != nullptr && temp->next->id != val)
        {
            temp = temp->next;
        }
        if(temp->next == nullptr){
            cout<<"There is no song in play list";
            return;
        }

        Song *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        return;
    }

    void display(){
        Song *temp = head;
        if (head == nullptr)
        {
            cout<<"empty play list";
            return;
        }
        
        while (temp->next != nullptr)
        {
            cout << temp->id << "|" << temp->name << "|" << temp->artist_name << "|" << temp->duration << endl;
            temp = temp->next;
        }
    }
};