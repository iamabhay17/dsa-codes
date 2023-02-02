// Reverse a linked list by changing nodes link

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

//----------------------reverse linked list----------------------------

void reverse(Node *&head)
{
    Node *temp = head;

    Node *newHead = NULL;
    while (head != NULL)
    {
        temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }

    head = newHead;
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

    // reverse linked list

    reverse(head);
    display(head);

    return 0;
}