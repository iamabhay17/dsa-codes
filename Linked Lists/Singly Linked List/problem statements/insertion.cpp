// Insertion in sorted linked list

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

//----------------------insertion at sorted Linked list----------------------------

void sortedInsert(Node *&head, int data)
{
    Node *temp = head;
    Node *insNode = new Node(data);
    Node *prev = NULL;

    // logic for first node
    if (temp == NULL || temp->data >= data)
    {
        insNode->next = temp;
        head = insNode;
        return;
    }
    // logic for middle
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }
    insNode->next = temp->next;
    temp->next = insNode;
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
    push(tail, 11);
    push(tail, 12);
    display(head);

    // reverse linked list

    sortedInsert(head, 10);
    display(head);
    sortedInsert(head, 2);
    display(head);

    return 0;
}