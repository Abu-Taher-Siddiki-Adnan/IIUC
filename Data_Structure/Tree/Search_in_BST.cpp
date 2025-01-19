#include <bits/stdc++.h>
using namespace std;

class BST
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node(int val)
        {
            this->left = NULL;
            this->right = NULL;
            this->val = val;
        }
    };

    Node *root;

    void insert(Node *&root, int item)
    {
        if (root == NULL)
        {
            root = new Node(item);
            return;
        }
        if (root->val > item)
        {
            insert(root->left, item);
        }
        else if (root->val < item)
        {
            insert(root->right, item);
        }
    }

    bool search(Node *root, int item)
    {
        if (root == NULL)
            return false;
        if (root->val == item)
            return true;
        if (root->val > item)
        {
            return search(root->left, item);
        }
        else
            return search(root->right, item);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int item)
    {
        insert(root, item);
    }

    bool search(int v)
    {
        return search(root, v);
    }
};

int main()
{
    BST bst;
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        bst.insert(v);
    }

    if (bst.search(x))
        cout << x << " Found in the BST" << endl;
    else
        cout << x << " Not Found in the BST" << endl;

    return 0;
}
