// insertion in doubly linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
//-------------------------------------insert at head-----------------------------------------------------
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    // insertion
    temp->next = head;
    head->prev = temp;
    head = temp;
}
//-------------------------------------insert at tail-----------------------------------------------------

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    // insertion at end
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

//--------------------------------------insert at nth position--------------------------------------------

void insertAt(Node *&head, int data, int pos)
{
    Node *temp = new Node(data);
    Node *itr = head;
    int count = 1;
    while (count < pos - 1)
    {
        itr = itr->next;
        count++;
    }
    // insertion
    temp->next = itr->next;
    itr->next->prev = temp;
    temp->prev = itr;
    itr->next = temp;
}

//---------------------------------------print data--------------------------------------------------------

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

//-----------------------------------------display rev------------------------------------------------------

void displayRev(Node *&tail)
{
    Node *temp = tail;
    cout << "Displaying in reverse order : ";

    while (temp->prev != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << temp->data << " " << endl;
}

int main()
{
    Node *newNode = new Node(5);
    Node *head = newNode, *tail = newNode;
    display(head);

    // insert at head
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    display(head);

    // insert at tail
    insertAtTail(tail, 15);
    insertAtTail(tail, 25);
    display(head);

    // insert at nth pos
    insertAt(head, 200, 2);
    display(head);

    // displayRev

    displayRev(tail);

    return 0;
}