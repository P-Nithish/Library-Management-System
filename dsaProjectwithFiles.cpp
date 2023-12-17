#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;
fstream myFile;


class Library
{
private:
    class Node
    {
    public:
        int id;
        string name, author, publisher;
        Node* next;
        Node()
        {
            this -> next = NULL;
        }
    };
public:
    Node* head = NULL;
    void menu();
    void insert_record();
    void search_record();
    void update_record();
    void del_record();
    void bubble_sort();
    void show_record();
    //void show();
    void showFileRecords();
};





void Library::menu()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n 1. Insert New Record";
    cout << "\n\n 2. Search Record";
    cout << "\n\n 3. Update Record";
    cout << "\n\n 4. Delete From Currently Added Record";
    cout << "\n\n 5. Show Currently Added Records";
    cout << "\n\n 6. Show All Records";
    cout << "\n\n 7. Exit";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    if(choice == 1)
    {
        insert_record();
    }
    else if(choice == 2)
    {
        search_record();
    }
    else if(choice == 3)
    {
        update_record();
    }
    else if(choice == 4)
    {
        del_record();
    }
    else if(choice == 5)
    {
        bubble_sort();
        show_record();
    }
    else if(choice == 6)
    {
        showFileRecords();
    }
    else if(choice == 7)
    {
        exit(0);
    }
    getch();
    goto p;
}

void Library::insert_record()
{
    system("cls");
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    Node* new_Node = new Node;
    cout << "\n\n Book ID : ";
    cin >> new_Node -> id;
    cout << "\n\n Name : ";
    cin >> new_Node -> name;
    cout << "\n\n Author Name : ";
    cin >> new_Node -> author;
    cout << "\n\n Publisher's Name : ";
    cin >> new_Node -> publisher;
    if(head == NULL)
    {
        head = new_Node;
    }
    else
    {
        Node* ptr = head;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        //ptr = new_Node;
        ptr -> next = new_Node;
    }
    cout << "\n\n\t\t\tNew Book Inserted Successfully.........";
    myFile.open("Library Records.txt", ios::app);
    myFile << "Book ID : " << new_Node -> id << endl;
    myFile << "Book Name : " << new_Node -> name << endl;
    myFile << "Book Author : " << new_Node ->author << endl;
    myFile << "Book Publisher : " << new_Node -> publisher << endl;
    myFile << endl;
    myFile.close();
}

void Library::search_record()
{
    system("cls");
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    if(head == NULL)
    {
        cout << "\n\n  No Entries Found !";
    }
    else
    {
        cout << "\n\n Book ID : ";
        int testID, flag = 0;
        cin >> testID;
        Node* ptr = head;
        while(ptr != NULL)
        {
            if(testID == ptr -> id)
            {
                system("cls");
                cout << "\n\n\t\t\t=========================================";
                cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
                cout << "\n\n\t\t\t=========================================";
                cout << "\n\n Book ID : " << ptr -> id;
                cout << "\n\n Book Name : " << ptr -> name;
                cout << "\n\n Author Name : " << ptr -> author;
                cout << "\n\n Publisher Name : " << ptr -> publisher;
                flag++;
            }
            ptr = ptr -> next;
        }
        if(flag == 0)
        {
            cout << "\n\n Book ID " << testID << " not found in records";
        }
    }
}

void Library::update_record()
{
    system("cls");
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    if(head == NULL)
    {
        cout << "\n\n  No Entries Found !";
    }
    else
    {
        cout << "\n\n Book ID : ";
        int testID, flag = 0;
        cin >> testID;
        Node* ptr = head;
        while(ptr != NULL)
        {
            if(testID == ptr -> id)
            {
                system("cls");
                cout << "\n\n\t\t\t=========================================";
                cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
                cout << "\n\n\t\t\t=========================================";
                cout << "\n\n Book ID : ";
                cin >> ptr -> id;
                cout << "\n\n Book Name : ";
                cin >> ptr -> name;
                cout << "\n\n Author Name : ";
                cin >> ptr -> author;
                cout << "\n\n Publisher Name : ";
                cin >> ptr -> publisher;
                flag++;
                cout<<"\n\n\t\t\tUpdate Book successfully.....";
            }
            ptr = ptr -> next;
        }
        if(flag == 0)
        {
            cout << "\n\n Book ID " << testID << " not found in records";
        }
    }

}

void Library::del_record()
{
    system("cls");
    int t_id, flag = 0;
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    if(head == NULL)
    {
        cout << "\n\n  No Entries Found !";
    }
    else
    {
        cout << "\n\n Book ID : ";
        cin >> t_id;
        if(t_id == head -> id)
        {
            Node* ptr = head;
            head = head -> next;
            delete ptr;
            cout << "\n\nDeleted Successfully.................";
            flag++;
        }
        else
        {
            Node* prev = head;
            Node* ptr = head;
            while(ptr != NULL)
            {
                if(t_id == ptr ->id)
                {
                    prev -> next = ptr -> next;
                    delete ptr;
                    cout << "\n\nDeleted Successfully.................";
                    flag++;
                    break;
                }
                prev = ptr;
                ptr = ptr -> next;
            }
        }
        if(flag == 0)
        {
            cout << "\n\n Book ID is invalid !!";
        }
    }
}

void Library::bubble_sort()
{
    if(head == NULL)
    {
        system("cls");
        cout << "\n\n\t\t\t=========================================";
        cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
        cout << "\n\n\t\t\t=========================================";
        cout<<"\n\n Linked List is empty......";
        getch();
        menu();
    }
    int count = 0,t_id;
    string t_name,t_author,t_publisher;
    Node* ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }
    for(int i=1; i<=count; i++)
    {
        Node* ptr = head;
        for(int j=1; j<count; j++)
        {
            if((ptr -> id) > (ptr -> next) -> id)
            {
                //Save data into temporary variables
                t_id = ptr -> id;
                t_name = ptr -> name;
                t_author = ptr -> author;
                t_publisher = ptr -> publisher;
                //Save data into current node
                ptr -> id = ptr -> next -> id;
                ptr -> name = ptr -> next -> name;
                ptr -> author = ptr -> next -> author;
                ptr -> publisher = ptr -> next -> publisher;
                //Save data into next node
                ptr -> next -> id = t_id;
                ptr -> next -> name = t_name;
                ptr -> next -> author = t_author;
                ptr -> next -> publisher = t_publisher;
            }
            ptr = ptr -> next;
        }
    }
}

void Library::show_record()
{
    system("cls");
    cout<<"\n\n\t\t\t====================================";
    cout<<"\n\n\t\t\t======LIBRARY MANAGEMENT SYSTEM=====";
    cout<<"\n\n\t\t\t====================================";
    Node *ptr = head;
    while(ptr != NULL)
    {
        cout<<"\n\n BOOK ID : "<<ptr->id;
        cout<<"\n\n BOOK NAME : "<<ptr->name;
        cout<<"\n\n BOOK AUTHOR : "<<ptr->author;
        cout<<"\n\n BOOK PUBLISHER : "<<ptr->publisher;
        cout<<"\n\n====================================";
        ptr=ptr->next;
    }
}

void Library::showFileRecords()
{
    system("cls");
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    myFile.seekp(0, ios::beg);
    string s;
    myFile.open("Library Records.txt");
    while(!myFile.eof())
    {
        getline(myFile,s);
        cout<<s<<endl;
    }
    //cout << myFile.tellp();

    //cout << myFile.tellg();
    myFile.close();
    getch();
    menu();
}

int main()
{
    Library obj;
    obj.menu();
    //ifstream inFile;

}






