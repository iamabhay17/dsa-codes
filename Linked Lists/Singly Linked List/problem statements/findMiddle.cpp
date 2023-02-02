// Finding middle of linked list

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

//----------------------middle of linked Linked list----------------------------

int middle(Node *&head)
{
    Node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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

    cout << "Middle of linked list is : " << middle(head) << endl;

    return 0;
}