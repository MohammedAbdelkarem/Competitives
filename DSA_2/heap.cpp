#include<bits/stdc++.h>
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
void maxheapify(int a[] , int n , int i) //in this algorithm we suppose that all nodes is max heap expect the target node (i) which we will fix it using maxheapify
{
    int right = 2*i+1 , left = 2*i+2 , largest = i;
    if(right < n and a[right] > a[i])
        largest = right;
    if(left < n and a[left] > a[i])
        largest = left;
    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxheapify(a , n , largest);
    }
}
void maxheapifygeneral(int a[] , int n , int curr) // this algorithm will fix all the heap regardless if it contain one target or multiple, it will fix them all
{
    if(curr == 0)
        return;
    int parent;
    if(curr % 2 == 0)
        parent = curr / 2 - 1;
    else
        parent = curr / 2;
    if(parent > 0 and a[parent] < a[curr])
    {
        int temp = a[parent];
        a[parent] = a[curr];
        a[curr] = temp;
    }
    maxheapifygeneral(a , n , curr-1);
}
int main()
{
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    maxheapifygeneral(a , n , n-1);
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
