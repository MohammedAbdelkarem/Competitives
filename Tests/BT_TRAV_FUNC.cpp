#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node *left, *right;
};
Node* node(int value)
{
    Node* node=new Node();
    node->value=value;
    node->left=node->right=NULL;
    return (node);
}
void printInOrder(Node* node) //left root right
{
    if(node==NULL)
        return;
    printInOrder(node->left);
    cout<<node->value<<" ";
    printInOrder(node->right);
}
void printPreOrder(Node* node) //root left right
{
    if(node==NULL)
        return;
    cout<<node->value<<" ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}
void printPostOrder(Node* node) //left right root
{
    if(node==NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<<node->value<<" ";
}
int search(int a[],int start,int end,int wanted)
{
    int ans=0;
    for(int i=start;i<end;i++)
        if(a[i] == wanted)
            return i;
}
Node* buildtree(int in[],int pre[],int start,int end)
{
   static int preindex=0;
    if(start>end)                                              //if the in order array end and there are no more elements, if there are no more elements in the tree
        return NULL;
    Node* tNode=node(pre[preindex++]);                      //or we  will make a node and give it the value of the first element in pre array
    if(start == end)                                            //if there are no more left subtree or there are no more right sub tree then we gonna return the current node and stop the recursive search operations
        return tNode; 
    int inIndex=search(in,start,end , tNode->value);            //or we gonna search int the left and the right subtree on the wanted elements recursively
    tNode->left=buildtree(in,pre,start,inIndex-1);
    tNode->right=buildtree(in,pre,inIndex+1,end);
    return tNode;
}
bool is_in_tree(Node* node,int wanted)
{
    if(node == NULL)                                                //if the tree or we are in the leaves and there are no result return false
        return false;
    if(node->value == wanted)                                       //if we found the wanted element return true
        return true;
    bool b1=is_in_tree(node->left,wanted);                          //or we gonna recheack the left child recursively
    if(b1)
        return true;                                                //if the left child is the wanted element return true;
    bool b2=is_in_tree(node->right,wanted);                         //or we gonna recheak the right child recursively and return its result(whethar it is true or false)
    return b2;
}
int max_hight(int n)
{
    return n-1;
}
int min_hight(int n)
{
    return floor(log2(n));
}
int min_num_nodes(int h)
{
    return h+1;
}
int max_num_nodes(int h)
{
    return pow(2,h+1)-1;
}
bool isfull(Node* root)
{
    if(root == NULL)                                        //if the tree isempty or we done fronm checking recursivly return true
        return true;
    if(root->left == NULL and root->right == NULL)            //if the node is leaf return true
        return true;
    if(root->left and root->right)                            //if there is tow childs then recheack them recursively
        return (isfull(root->left) and isfull(root->right));
    return false;
}
int _depth(Node* root)
{
    int ans=0;
    while(root != NULL)
    {
        ans++;
        root=root->left;
    }
    return ans;
}
bool isperfect(Node* root,int depth,int level=0)
{
    if(root == NULL)                     //if the treeempty return true
        return true;
    if(root->left == NULL and root->right == NULL)       //if there is two leafs then there depth must be as the real depth or they must be in the last level
        return (depth == level+1);
    if(root->left == NULL  or root->right == NULL)          //if there is just one child to the node return false
        return false;
    return (isperfect(root->left,depth,level+1)  and  isperfect(root->right,depth,level+1));     //  recheack the childs with a new level
}
int left_hight(Node* root)
{
    int ans=0;
    while(root != NULL)
    {
        ans++;
        root=root->left;
    }
    return ans;
}
int right_hight(Node* root)
{
    int ans=0;
    while(root != NULL)
    {
        ans++;
        root=root->right;
    }
    return ans;
}
int total_nodes_num(Node* root)
{
    if(root == NULL)                                    //if the tree is empty return that the number is zero
        return 0;
    if(right_hight(root) == left_hight(root))           //if it is full tree then the hight will be 2^h+1 -1
        return pow(2,left_hight(root)+1)-1;
    return 1 + total_nodes_num(root->left) + total_nodes_num(root->right);
}
int leavs_num(Node* root)
{
    if(root == NULL)                                       // if the tree is empty ot we are on a empty node(out of the tree during recursive call)return 0 because there are no node
        return 0;
    if(root->left == NULL and root->right == NULL)          //if the node have no childs then its a leaf so return 1
        return 1;
    return leavs_num(root->left) + leavs_num(root->right);     //make a recursive call for the rest of the tree
}
int not_leavs_num(Node* root)
{
    if(root == NULL)                                              //if its not node return 0
        return 0;
    if(root->left or root->right)                                //if the node have one or maro child then it is a internal node then return 1
        return 1;
    return not_leavs_num(root->left) + not_leavs_num(root->right);    //check the rest of the tree recursively
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool is_in_bst(Node* root,int wanted)
{
    if(root == NULL)
        return false;
    if(root->value == wanted)
        return true;
    if(root->value > wanted)
        return is_in_bst(root->left,wanted);
    return is_in_bst(root->right,wanted);
} 
bool is_in_bst_iteration(Node* root,int wanted)
{
    while(root != NULL)
    {
        if(root->value == wanted)
            return true;
        else if(root->value > wanted)
            root=root->left;
        else    
            root=root->right;
    }
    return false;
}
Node* insert(Node* root,int value)
{
    if(root == NULL)
    {
        root=node(value);
        return root;
    }
    if(value > root->value)
        root->right=insert(root->right,value);
    if(value < root->value)
        root->left=insert(root->left,value);
    return root;
}
bool isbst(Node* root)
{
    if(root == NULL)
        return true;
    if(root->left)
        if(root->left->value > root->value)
            return false;
    if(root->right)
        if(root->right->value <= root->value)
            return false;
    return isbst(root->left) and isbst(root->right);
}

int main()
{
    int size;
    cout<<"enter tree size"<<endl;
    cin>>size;
    // int in[size],pre[size];
    // cout<<"enter inorder array then press enter then enter preorder array"<<endl;
    // for(int i=0;i<size;i++)
    //     cin>>in[i];
    // for(int i=0;i<size;i++)
    //     cin>>pre[i];
   // Node* root=buildtree(in,pre,0,size-1);
   // cout<<"enter the value you want to check its existing"<<endl;
    //int x;cin>>x;
    // if(is_in_tree(root,x))
    //     cout<<x<<" in the tree"<<endl;
    // else    
    //     cout<<x<<" is not in  the tree"<<endl;
    //cout<<min_hight(size)<<"  "<<max_hight(size)<<endl;


    





/*
inorder:  1 5 10 13 15 17 20
preorder: 15 10 5 1 13 20 17
*/





//     struct Node* root=newnode(1);
//     root->left=newnode(2);
//     root->right=newnode(3);
//     root->left->left=newnode(4);
//     root->left->right=newnode(5);
//    // root->right->left=newnode(6);
//     root->right->right=newnode(7);
//     printInOrder(root);
}