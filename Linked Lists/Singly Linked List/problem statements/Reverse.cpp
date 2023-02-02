// reverse a linked list without changing links of node

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

//----------------------------inserting data-------------------------------

void push(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = tail->next;
}

//----------------------------printing data---------------------------------

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

//-----------------------------revrese head----------------------------------

void reverse(Node *&head)
{
    Node *temp = head;
    vector<int> vec;

    while (temp != NULL)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }

    temp = head;
    int n = vec.size() - 1;
    while (temp != NULL)
    {
        temp->data = vec[n--];
        temp = temp->next;
    }
}

//------------------------------main fn---------------------------------------

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

    // reverse
    reverse(head);
    display(head);
}