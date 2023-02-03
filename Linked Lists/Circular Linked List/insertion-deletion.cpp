// insertion & deletion in circular linkd list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// print
void print(Node *&head)
{
    Node *temp = head;
    do
    {

        cout << temp->data << " ";
        temp = temp->next;

    } while (head != temp);

    cout << endl;
    return;
}

// insertion
void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is empty,Check again" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = tail->next;

        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
        return;
    }
}

int main()
{
    Node *tail = NULL;

    // inserting data
    insertNode(tail, 1, 3);
    insertNode(tail, 3, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 9, 11);
    insertNode(tail, 7, 1);
    // printing data;
    print(tail);
    deleteNode(tail, 1);
    print(tail);

    return 0;
}