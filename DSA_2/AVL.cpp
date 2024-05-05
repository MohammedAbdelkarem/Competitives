#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data; 
    Node *left , *right;
};
Node* node(int value)
{
    Node* node = new Node();
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
int hight(Node* root)
{
    if(root == NULL)
        return -1;
    return 1 + hight(root->left) + hight(root->right);
}
int BF(Node* root)
{
    if(root == NULL)
        return 0;
    return hight(root->left) - hight(root->right);
}
Node* right_rotate(Node* x)
{
    Node* y = x->left; 
    Node* d = y->right;
    y->right = x;
    x->left = d;
}
Node* left_rotate(Node* x)
{
    Node* y = x->right;
    Node* d = y->left;
    y->left = x;
    x->right = d;
}
Node* insert(Node* root , int key)
{
    Node* n = node(key);
    if(root == NULL)
        root = n;
    else
    {
        if(root->data > key)
            root->left = insert(root->left , key);
        else if(root->data < key)
            root->right = insert(root->right , key);
    }
    return root;
    if(BF(root) > 1)
    {
        if(root->left->data > key)
            return right_rotate(root);
        if(root->left->data < key)
        {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }
    if(BF(root) < -1)
    {
        if(root->right->data < key)
            return left_rotate(root);
        if(root->right->data > key)
        {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }
}
int main()
{
    Node* root = node(1);
}