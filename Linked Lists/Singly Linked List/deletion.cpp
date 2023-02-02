// deletion in singly linked list

#include <bits/stdc++.h>
using namespace std;

//--------------------NOde class---------------------------------
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
//--------------------Insertion for help------------------------------------
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    // inserting data
    tail->next = temp;
    tail = tail->next;
}

//--------------------Printing LL----------------------------------------

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//-------------------deletion at head of linked list--------------------------

void deleteStart(Node *&head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Cannot delete (NOde empty)." << endl;
    }
    // deletion
    head = head->next;
    cout << "Node deleted : " << temp->data;
    free(temp);
    cout << endl;
}

//-----------------delete from end of ll-----------------------------------------

void deleteEnd(Node *&head)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // if node is empty
    if (temp == NULL)
    {
        cout << "Cannot delete (NOde empty)." << endl;
    }

    // deleting node
    prev->next = NULL;
    cout << "Node deleted : " << temp->data;
    free(temp);
    cout << endl;
}

//-----------------------delete at nth position--------------------------------

void deleteAt(Node *&head, int pos)
{
    Node *temp = head;
    Node *prev = NULL;
    int count = 1;

    if (pos == 1)
    {
        deleteStart(head);
    }
    // iterating to nth position
    while (count != pos)
    {
        count++;
        prev = temp;
        temp = temp->next;
    }
    // deletion logic
    prev->next = temp->next;
    cout << "Node deleted : " << temp->data;
    free(temp);
    cout << endl;
}

//------------------------main program---------------------------------------------
int main()
{
    Node *newNode = new Node(4);
    Node *head = newNode, *tail = newNode;
    // data to be used
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    print(head);

    // delete from beginning
    deleteStart(head);
    print(head);

    // delete from end
    deleteEnd(head);
    print(head);

    // delete from a position
    deleteAt(head, 2);
    print(head);

    return 0;
}