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
void inorder(Node* root) // left root right
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root) //root left right
{
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root ->right);
}
void postorder(Node* root) //left right root
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
bool exist(Node* root , int key)
{
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;
    bool res1 = exist(root->left , key);
    bool res2 = exist(root->right , key);
    if(res1 or res2)
        return true;
    return false;
}
int max_hight(int n)
{
    return n-1;
}
int min_hight(int n)
{
    return floor(log2(n));
}
int min_nodes_num(int h)
{
    return h+1;
}
int max_nodes_num(int h)
{
    return pow(2 , h+1) - 1;
}
int max_left(Node* root)
{
    if(root == NULL)
        return -1;
    return 1 + max_left(root->left);
}
int max_right(Node* root)
{
    if(root == NULL)
        return -1;
    return 1 + max_right(root->right);
}
int leaf_num(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL and root->right == NULL)
        return 1;
    return leaf_num(root->left) + leaf_num(root->right); 
}
int internal_nodes_num(Node* root)
{
    if(root == NULL or (root->left  == NULL and root->right == NULL))
        return 0;
    return 1 + internal_nodes_num(root->left) + internal_nodes_num(root->right);
}
int main()
{
    Node* root = node(1);
    root->left=node(2);
    root->right=node(3);
    root->left->left=node(4);
    root->left->right=node(5);
    root->right->left=node(6);
    root->right->right=node(7);
}