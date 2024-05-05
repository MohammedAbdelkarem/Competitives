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
void swap(int& first , int& second)
{
    int temp = first;
    first = second;
    second = temp;
}
void heapify_bottom_up(int a[] ,int n,int i)  // 
{
    int parent = (i-1) / 2;
    if(a[i] > a[parent])
    {
        swap(a[i] , a[parent]);
        heapify_bottom_up(a,n,parent);
    }
}
void heapify_top_dwon(int a[] , int n , int i)
{
    int left_child = 2*i + 1 , right_child = 2*i + 2;
    int largest = i;
    if(left_child < n and a[left_child] > a[largest])
        largest = left_child;
    if(right_child < n and a[right_child] > a[largest])
        largest = right_child;
    if(largest != i)
    {
        swap(a[i] , a[largest]);
        heapify_top_dwon(a,n,largest);
    }
}
int main()
{
    int n;cin>>n;
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}