// Print reverse of a linked list without actually reversing it

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->next = NULL;
        this->data = d;
    }
};

//--------------------inserting data----------------------------------
void push(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = tail->next;
}

//-----------------------display---------------------------------------

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//----------------------search----------------------------

void search(Node *&head, int data)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << "Element is present at : " << count;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << data << "not present in array";
}

//-----------------------main-fn-----------------------------------------

int main()
{
    Node *newNode = new Node(5);
    Node *head = newNode, *tail = newNode;

    // data to be used
    push(tail, 6);
    push(tail, 7);
    push(tail, 8);
    push(tail, 9);
    push(tail, 10);
    push(tail, 11);
    display(head);

    // search linked list

    search(head, 77);

    return 0;
}