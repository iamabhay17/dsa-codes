// implementation of binary tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *build(Node *root)
{
    int data;
    cout << "Enter Data: ";
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left node of " << data << endl;
    root->left = build(root->left);

    cout << "Enter data for right node of " << data << endl;
    root->right = build(root->right);

    cout << endl;
    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    // building tree
    root = build(root);

    // level order
    levelOrder(root);

    // preorder
    cout << "Pre Order : ";
    preorder(root);
    cout << endl;

    // preorder
    cout << "post Order : ";
    postorder(root);
    cout << endl;

    // inorder
    cout << "InOrder : ";
    inorder(root);
    cout << endl;

    return 0;
}
