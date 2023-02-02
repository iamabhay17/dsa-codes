// write a C++ program to append the last n nodes of a linked list to the beginning of the list

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

//----------------------append k nodes----------------------------

Node *appendK(Node *head, int k)
{

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < k; i++)
    {

        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
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

    // append k nodes

    head = appendK(head, 4);
    display(head);

    return 0;
}