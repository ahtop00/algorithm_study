//이진 검색 트리
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;

    Node()
    {
        data = -1;
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    Node(int data, Node *n)
    {
        this->data = data;
        parent = n;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    BST();
    Node *isRoot();
    void push(int data);
    void postOrder(Node *n);

private:
    Node *root;
    int size;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BST bst;
    int data;
    cin >> data;
    while (!cin.eof())
    {
        bst.push(data);
        cin >> data;
    }

    bst.postOrder(bst.isRoot());
}

BST::BST()
{
    size = 0;
    root = new Node();
}

Node *BST::isRoot()
{
    return root;
}

void BST::push(int data)
{
    if (size == 0)
    {
        root->data = data;
        size++;
        return;
    }

    Node *current = root;
    while (1)
    {
        if (current->data > data)
        {
            if (current->left == NULL)
            {
                current->left = new Node(data, current);
                size++;
                return;
            }
            else
            {
                current = current->left;
            }
        }
        else // current-> data <= data
        {
            if (current->right == NULL)
            {
                current->right = new Node(data, current);
                size++;
                return;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

void BST::postOrder(Node *n)
{
    if (n == NULL)
    {
        return;
    }

    postOrder(n->left);
    postOrder(n->right);
    cout << n->data << "\n";
}