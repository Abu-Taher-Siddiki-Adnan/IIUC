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

    void pre_order(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val << " ";
        pre_order(root->left);
        pre_order(root->right);
    }

    void in_order(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        in_order(root->left);
        cout << root->val << " ";
        in_order(root->right);
    }

    void post_order(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        post_order(root->left);
        post_order(root->right);
        cout << root->val << " ";
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

    void pre_order()
    {
        pre_order(root);
    }

    void in_order()
    {
        in_order(root);
    }

    void post_order()
    {
        post_order(root);
    }
};

int main()
{
    BST bst;
    int n;
    cin >> n ;

    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        bst.insert(v);
    }

    cout << "Pre-order: ";
    bst.pre_order();
    cout << endl;

    cout << "In-order: ";
    bst.in_order();
    cout << endl;

    cout << "Post-order: ";
    bst.post_order();
    cout << endl;

    return 0;
}
