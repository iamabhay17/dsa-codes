#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // using seperator

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        // rest of the code
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
}

Node *insertIntoBst(Node *&root, int data)
{
    // base case

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // consdition 1
    if (data > root->data)
    {
        root->right = insertIntoBst(root->right, data);
    }
    else
    {
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// inorder traversal - LNR

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// preOrder traversal - NLR

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// postOrder traversal - LRN

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// minVal

Node *minVal(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return minVal(root->left);
}

// maxVal

Node *maxVal(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return maxVal(root->right);
}

Node *deleteFromBST(Node *&root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == data)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root->left;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root->right;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }
    else if (root->data > data)
    {
        root->left = deleteFromBST(root->left, data);
        return root;
    }
    else
    {

        root->right = deleteFromBST(root->right, data);
        return root;
    }
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST" << endl;

    takeInput(root);

    cout << endl
         << "Level order : " << endl;
    levelOrder(root);
    cout << endl
         << "In order : " << endl;
    inOrder(root);
    cout << endl
         << "pre order : " << endl;
    preOrder(root);
    cout << endl
         << "post order : " << endl;
    postOrder(root);

    cout << endl
         << "Min Val : " << minVal(root)->data << endl;

    cout << endl
         << "Max Val : " << maxVal(root)->data << endl;
    root = deleteFromBST(root, 11);

    levelOrder(root);

    return 0;
}