// insert at head and insert at tail;

#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------NOde class --------------------------------------------------------------
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

//------------------------------------------insert at head-----------------------------------------
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);

    // adding data at head;
    temp->next = head;
    head = temp;
}

//-------------------------------------------insert at tail------------------------------------------------------------------

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    // adding data at tail
    tail->next = temp;
    tail = tail->next;
}

//------------------------------------------insert at nth position------------------------------------------------

void insertAt(Node *&head, int data, int pos, Node *&tail)
{
    Node *copy = head;
    int count = 1;

    while (count < pos - 1)
    {
        count++;
        copy = copy->next;
    }

    // if it reaches end
    if (copy->next == NULL)
    {
        insertAtTail(tail, data);
    }

    Node *temp = new Node(data);
    // logic
    temp->next = copy->next;
    copy->next = temp;
}

// -----------------------------------------printing linked list--------------------------------------------------
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *element = new Node(5);
    Node *head = element;
    Node *tail = element;
    // initial state
    cout << "Priting initial node: ";
    print(head);

    // insertion at head
    insertAtHead(head, 10);
    cout << "Value after inserting at head : ";
    print(head);

    // insert at tail
    insertAtTail(tail, 20);
    cout << "Value after inserting at tail : ";
    print(head);

    // insert at nth position
    insertAt(head, 100, 2, tail);
    cout << "Value after inserting at nt position : ";
    print(head);

    return 0;
}