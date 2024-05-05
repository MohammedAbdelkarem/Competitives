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
void insert_iteration(Node* root , int key)
{
    Node* n =node(key);
    if(root == NULL)
    {
        root = n;
        return;
    }
    Node* prev = NULL ;Node* temp = root;
    while(temp != NULL)
    {
        prev = temp;
        if(key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(key > prev->data)
        prev->right = n;
    else  
        prev->left = n;
}
Node* insert_recu(Node* root , int key)
{
    Node* n = node(key);
    if(root == NULL)
        root = n;
    if(root->data > key)
        root->left = insert_recu(root->left , key);
    else if(root->data < key)
        root->right = insert_recu(root->right , key);
    return root;
}
bool iter_exist(Node* root , int key)
{
    if(root == NULL)
        return false;
    while(root != NULL)
    {
        if(root->data == key)
            return true;
        if(root->data > key)
            root = root->left;
        else    
            root = root->right;
    }
    return false;
}
Node* recu_exist(Node* root , int key)
{
    if(root == NULL or root->data == key)
        return root;
    if(root->data > key)
       return root->left = recu_exist(root->left , key);
    if(root->data < key)
       return root->right = recu_exist(root->left , key);
}
void inorder(Node* root) // left root right
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool isbst(Node* root , Node* l , Node* r)
{
    if(root == NULL)
        return true;
    if(l and root->data <= l->data)
        return false;
    if(r and root->data >= r->data)
        return false;
    return isbst(root->left , l , root) and isbst(root->right , root , r);
}
Node* lca(Node* root , int n1 , int n2)
{
    if(root == NULL)
        return root;
    if(root->data > n1 and root->data > n2)
        return lca(root->left , n1 , n2);
    if(root->data < n1 and root->data < n2)
        return lca(root->right , n1 , n2);
    return root;
}
int distance(Node* root ,int key)
{
    if(root->data == key)
        return 0;
    else if(root->data > key)
        return 1 + distance(root->left , key);
    else    
        return 1 + distance(root->right , key);
}
int shortest_path(Node* root , int a ,int b)
{
    Node* newroot = lca(root , a , b);
    return distance(newroot , a) + distance(newroot , b);
}
int main()
{
    Node* root = node(4);
    insert_iteration(root , 2);
    insert_iteration(root , 6);
    insert_iteration(root , 1);
    insert_iteration(root , 3);
    insert_iteration(root , 5);
    insert_iteration(root , 7);
    cout<<shortest_path(root , 2 , 5);
}