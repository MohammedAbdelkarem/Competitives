#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node *left, *right;
    int height;
};
Node* node(int value)
{
    Node* node=new Node();
    node->value=value;
    node->left=node->right=NULL;
    return (node);
}
bool ispositive(int n)
{
    return n > 0;
}
bool isnegative(int n)
{
    return n < 0;
}
int hight(Node* root)
{
    if(root == NULL)
        return 0;
    return root->height;
}
int getBalance(Node* root)
{
    if(root == NULL)   
        return 0;
    return hight(root->left) - hight(root->right);
}
Node* rightRotate(Node* x)
{
    Node* y = x->right;
    Node* d = y->right;
    y->right = x;
    x->left  = d;
    y->height = max(1 + hight(y) , hight(x));
    x->height = max(1 + hight(x) , hight(y));
    return y;
}
Node* leftRotate(Node* y)
{
    Node* x = y->right;
    Node* d = x->left;
    x->left = y;
    y->right = d;
    y->height = max(1 + hight(y) , hight(x));
    x->height = max(1 + hight(x) , hight(y));
    return x;
}
Node* insert(Node* root , int key)
{
    if(root == NULL)
        return node(key);
    else
    {
        if(key > root->value)
            root->right = insert(root->right , key);
        else if(key < root->value)
            root->left = insert(root->left , key);
        else   
            return root;
    }
    int bf = getBalance(root);
    if(bf > 1)
    {
        if(key < root->left->value)
            return rightRotate(root);
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    else if(bf < 1)
    {
        if(key > root->right->value)
            return leftRotate(root);
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);        
        }
    }
}

int main()
{
    
}