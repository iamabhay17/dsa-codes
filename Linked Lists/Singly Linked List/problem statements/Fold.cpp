// fold a linked list

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
//------------------------reverse list----------------------------------------------------

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

//----------------------append k nodes----------------------------

void fold(Node *&head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;

    // reversing second half of linked list
    reverse(head2);

    head = new Node(0);

    Node *curr = head;
    while (head1 || head2)
    {
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    head = head->next;
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

    // fold a linked list
    fold(head);
    display(head);

    return 0;
}