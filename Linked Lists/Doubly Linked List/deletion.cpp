// deletion in doubly linked list

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

//------------------------------------delete at head-----------------------------------------------------

void popStart(Node *&head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;

    free(temp);
}

//-------------------------------------delete at tail-----------------------------------------------------

void popBack(Node *&tail)
{
    Node *temp = tail;
    tail = tail->prev;
    temp->prev->next = NULL;
    free(temp);
}

//-------------------------------------delete nth node----------------------------------------------------

void pop(Node *&head, int pos)
{
    Node *temp = head;
    int count = 1;

    while (count < pos)
    {
        count++;
        temp = temp->next;
    }

    // deletion

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
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

    // delete from nth pos
    cout << "Delete from nth pos : " << endl;
    pop(head, 3);
    display(head);

    // delete from head
    cout << "Delete from head : " << endl;
    popStart(head);
    display(head);

    // delete from tail
    cout << "Delete from tail : " << endl;
    popBack(tail);
    display(head);

    return 0;
}