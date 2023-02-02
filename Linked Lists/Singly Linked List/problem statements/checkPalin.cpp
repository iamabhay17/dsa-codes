// write a C++ program to check if a linked list is palindrome

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

//----------------------check palindrome----------------------------

bool checkPalin(Node *head)
{

    Node *temp = head;
    vector<int> vec;

    while (temp != NULL)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    int i = vec.size() - 1;
    while (temp != NULL)
    {
        if (temp->data != vec[i--])
        {
            return false;
        }
    }
    return true;
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

    cout << "Linked list palindrome : " << checkPalin(head);

    return 0;
}