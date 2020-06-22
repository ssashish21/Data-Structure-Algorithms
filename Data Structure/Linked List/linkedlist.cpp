// Linked List CPP
#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class List
{
    Node *head;
    Node *tail;
    Node *temp;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int x)
    {
        temp = new Node;
        temp->data = x;
        if(isEmpty())
        {
            temp->next = NULL;
            tail = temp;
        }
        else
            temp->next = head;
        head = temp;
    }

    void insertAtEnd(int x)
    {
        temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove(int x)
    {
        temp = head;
        Node *prev;
        while(temp->next != NULL && temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->data == x)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void find(int x)
    {
        int i;
        for(i=1, temp = head;temp->next != NULL && temp->data != x;temp = temp->next, i++);
        if(temp->data == x)
        {
            cout << "Found at position:" << i << endl;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};

int main()
{
    List l;
    l.display();
    l.insert(15);
    l.display();
    l.insert(25);
    l.display();
    l.insert(35);
    l.display();
    l.insert(45);
    l.display();
    l.find(15);
    l.remove(25);
    l.display();
    l.insertAtEnd(55);
    l.insertAtEnd(65);
    l.display();
}