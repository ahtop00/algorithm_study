//트리 순회
#include <iostream>
using namespace std;

struct Node
{
    string alphabet;
    Node *parent;
    Node *left;
    Node *right;

    Node()
    {
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    Node(string str, Node *n)
    {
        alphabet = str;
        parent = n;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Tree();
    Node *isRoot();
    Node *find(Node *n, string parent);
    void insert(string parent, string left, string right);
    void preOrder(Node *n);
    void inOrder(Node *n);
    void postOrder(Node *n);

private:
    Node *root;
    int size;
};

int main()
{
    int N;
    Tree tree;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string parent, left, right;
        cin >> parent >> left >> right;
        tree.insert(parent, left, right);
    }

    tree.preOrder(tree.isRoot());
    cout << "\n";
    tree.inOrder(tree.isRoot());
    cout << "\n";
    tree.postOrder(tree.isRoot());
}

Tree::Tree()
{
    root = NULL;
    size = 0;
}

Node *Tree::isRoot()
{
    return root;
}

void Tree::insert(string parent, string left, string right)
{
    if (size == 0)
    {
        root = new Node();
        root->alphabet = parent;
        if (left != ".")
        {
            root->left = new Node(left, root);
            size++;
        }
        if (right != ".")
        {
            root->right = new Node(right, root);
            size++;
        }
        size++;
        return;
    }

    Node *parent_node = find(root, parent);
    if (left != ".")
    {
        parent_node->left = new Node(left, parent_node);
        size += 1;
    }
    if (right != ".")
    {
        parent_node->right = new Node(right, parent_node);
        size += 1;
    }
}

Node *Tree::find(Node *n, string str)
{
    if (n == NULL)
    {
        return NULL;
    }

    if (n->alphabet == str)
    {
        return n;
    }

    Node *left_check = find(n->left, str);
    Node *right_check = find(n->right, str);

    if (left_check != NULL)
    {
        return left_check;
    }

    if (right_check != NULL)
    {
        return right_check;
    }

    return NULL;
}

void Tree::preOrder(Node *n)
{
    if (n == NULL)
    {
        return;
    }

    cout << n->alphabet;
    preOrder(n->left);
    preOrder(n->right);
}

void Tree::inOrder(Node *n)
{
    if (n == NULL)
    {
        return;
    }

    inOrder(n->left);
    cout << n->alphabet;
    inOrder(n->right);
}

void Tree::postOrder(Node *n)
{
    if (n == NULL)
    {
        return;
    }

    postOrder(n->left);
    postOrder(n->right);
    cout << n->alphabet;
}