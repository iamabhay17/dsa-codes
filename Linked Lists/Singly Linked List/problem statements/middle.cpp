// Insert element at middle of linked list

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

//----------------------insert at middle----------------------------

// i am using slow-fast pointer approach

void insertAtMiddle(Node *&head, int data)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = new Node(data);
    temp->next = slow->next;
    slow->next = temp;
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

    insertAtMiddle(head, 77);
    display(head);

    return 0;
}