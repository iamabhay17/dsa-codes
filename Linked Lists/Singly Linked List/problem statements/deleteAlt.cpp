// delete alternamtive nodes of a linked list

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

//----------------------delete alt----------------------------

void deleteAlt(Node *&head)
{
    Node *temp = head;
    Node *toBeFree = NULL;
    while (temp->next != NULL)
    {
        temp->next = temp->next->next;
        temp = temp->next;
    }
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

    deleteAlt(head);
    display(head);

    return 0;
}