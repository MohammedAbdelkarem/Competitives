#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value,hi;
    Node *left, *right;
};
Node* node(int value)                                           //fun to construct the node with the given value
{
    Node* node=new Node();
    node->value = value;
    node->left = node->right = NULL;
    return (node);
}
bool search_iteration(Node* root, int key)                        //fun to search int BST iteratively
{
    while(root != NULL)                                                        //while the tree does not end yet
    {
        if(root->value == key)                                                        //if we found the wanted value then return true
            return true;
        else if(root->value > key)                                                    //if the value of the node is bigger than the wanted value then go left along the tree,because we want value less than the node value and that will be in the left path in the BST
            root = root->left;
        else    
            root = root->right;                                                      //if the value of the node is smaller than the wanted value then go right along the tree,because we want value bigger than the node value and that will be in the right path in the BST    
    }
    return false;                                                              //if the tree end and we did not found our value then the it is not exist in the tree so return false
}
void insert_iteration(Node* root, int key)                       //fun to insert a node iteratively
{
    Node* newnode = node(key);                                                 //create a node and give it a value
    if(root == NULL)                                                           //if the tree is empty then just set the new node to the current node and end the fun
    {
        root = newnode;
        return ;
    }
    Node* prev = NULL;                                                         //we will create two nodes: prev and curr, and we will walk along the tree until we find a leaf
    Node* curr = root;                                                         //then when we find a leaf:curr is equal to null, so the prev node is the leaf
    while(curr != NULL)
    {
        if(curr->value > key)
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            prev = curr;
            curr = curr->right;
        }
    }
    if(prev->value > key)                                                       //since we find the leaf we add the new node left of the leaf or right of it , that is depending on leaf value and BST concepts
        prev->left = newnode;
    else    
        prev->right = newnode;
}
Node* min_value(Node* root)                                                     //fun to return the successor node which is the min value node in the right subtree
{
    Node* curr = root;
    while(curr != NULL and curr->left != NULL)
        curr = curr->left;
    return curr;
}
Node* max_value(Node* root)                                                     //fun to return the predecessor node which is the max value node in the left subtree
{
    Node* curr = root;
    while(curr != NULL and curr->right != NULL) 
        curr = curr->right;
    return curr;
}
int minimum_value(Node* root)
{
    Node* curr = root;
    while(curr != NULL and curr->left != NULL)
        curr = curr->left;
    return curr->value;
}
int maximum_value(Node* root)
{
    Node* curr = root;
    while(curr != NULL and curr->right != NULL)
        curr = curr->right;
    return curr->value;
}
Node* delete_node(Node* root, int key)                                         //fun to delete a node from BST
{
    if(root == NULL)                                                                       //if the tree is empty , it is the base case
        return root;
    if(root->value > key)                                                                  //if the current node has a value bigger than the wanted value
        root->left = delete_node(root->left, key);                                         //then we need smaller value so go left along the tree
    else if(root->value < key)                                                             //if the current node has a value smaller then the wanted value
        root->right = delete_node(root->right, key);                                       //then we need bigger value so go right along the tree
    else                                                                                   //if we find the wanted node
    {
        if(root->left == NULL and root->right == NULL)                                     //if it has no childs then we just delete it without any changes
            return NULL;
        else if(root->left == NULL)                                                              //if it has one child, we will deelte it and return the child(replace it with the child)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)                                                               //if it has one child, we will deelte it and return the child(replace it with the child)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else                                                                                       //if it has two childs, we will replace it with the predecessor or max_value in the left subtree(we usually repalce it with the successor but in the task we will replace it with the predecessor)
        {
            Node* temp = max_value(root->left);                                                            //find the predecessor 
            root->value = temp->value;                                                                     //set predecessor value to the deleted node
            root->right = delete_node(root->left, temp->value);                                            //now delete the predecessor from the tree
        }
    }
    return root;
}
void printspace(double n, Node* removed)
{
    for(; n > 0 ; n--)
        cout<<"\t";
    if(removed ==   NULL)
        cout<<" ";
    else
        cout<<removed->value;
}
int _hight(Node* root)
{
    if(root == NULL)
        return 0;
    return 1+max(_hight(root->left) , _hight(root->right));
}
void print_tree(Node* root)
{
    queue<Node*>treelevel,temp;
    treelevel.push(root);
    int c = 0, hight = _hight(root) - 1;
    double num_of_elements = pow(2,(hight + 1)) - 1;
    while(c <= hight)
    {
        Node* removed = treelevel.front();
        treelevel.pop();
        if(temp.empty())
            printspace(num_of_elements / pow(2 , c + 1) , removed);
        else
            printspace(num_of_elements / pow(2 , c) , removed);
        if(removed == NULL)
        {
            temp.push(NULL);
            temp.push(NULL);
        }
        else
        {
            temp.push(removed->left);
            temp.push(removed->right);
        }
        if(treelevel.empty())
        {
            cout<<endl<<endl;
            treelevel = temp;
            while(!temp.empty())
                temp.pop();
            c++;
        }
    }
}
void store_nodes(Node* root, vector<Node*> &v)                //fun to stroe the nodes as inorder
{
    if(root == NULL)
        return;
    store_nodes(root->left,v);
    v.push_back(root);
    store_nodes(root->right,v);
}
Node* build_balanced(vector<Node*> &v, int start, int end)      //fun to build a balanced or avl tree depending on the inorder form which is sorted in the vector by store_nodes fun
{
    if(start > end)
        return NULL;
    int mid=(start + end) / 2;
    Node* root = v[mid];                                               //we willl start from the middle tree because it is the root during to the inordr form
    root->left = build_balanced(v , start , mid - 1);                  //build the left subtree recursively by taking the elements left of the root 
    root->right = build_balanced(v , mid + 1 , end);                   //build the right subtree recursively by taking the elements right of the root
    return root;
}
Node* To_AVL(Node* root)                                    //fun to convert the BST to AVL tree
{
    vector<Node*> v;                                              //we need vector to store in it the nodes of the tree
    store_nodes(root , v);                                        //store_node fun , the explain is above
    return build_balanced(v , 0 , v.size()-1);                    //build_balanced fun , the explain is above
}
int height(Node* root)
{
    if(root == NULL)
        return -1;
    return 1 + max(height(root->left) , height(root->right));
}
int main()
{
    Node* root = node(15);
    insert_iteration(root , 1);
    insert_iteration(root , 2);
    insert_iteration(root , 2);
    insert_iteration(root , 9);
    insert_iteration(root , 7);
    insert_iteration(root , 20);
    insert_iteration(root , 27);
    //insert_iteration(root , 5);
    //print_tree(root);
    //delete_node(root , 7);
    //print_tree(root);
    //cout<<minimum_value(root)<<endl;
    // print_tree(root);
    // To_AVL(root);
    //print_tree(root);
    cout<<height(root);













// Node* root = node(15);
// root->left=node(10);
// root->right=node(20);
// root->left->left=node(8);
// root->left->right=node(12);
// root->right->left=node(13);
// root->right->right=node(2);
// print_tree(root);
}