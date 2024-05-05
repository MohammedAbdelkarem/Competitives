#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
map<int,bool>visited;
queue<int>q;
bool b=0;
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
void create_graph(int n)
{
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        auto it=visited.begin();
        it=visited.emplace_hint(it,i,0);
    }
}
void add_edge(int u , int vv)
{
    v[u].push_back(vv);
}
void print_dfs(int vertix)
{
    visited[vertix] = 1;
    cout<<vertix<<" ";
    for(int i=0;i<v[vertix].size();i++)
        if(!visited[v[vertix][i]])
            print_dfs(v[vertix][i]);

}
void print_bfs(int vertix)
{
    if(!b)
    {
        q.push(vertix);
        b=1;
    }
    for(int i=0;i<v[vertix].size();i++)
            q.push(v[vertix][i]);
    while(!q.empty())
    {
        if(!visited[q.front()])
        {
            visited[q.front()] = 1;
            cout<<q.front()<<" ";
        }   
        q.pop();
        print_bfs(q.front());
    }
}
int main()
{
    create_graph(8);
    add_edge(0,1);
    add_edge(0,2);
    add_edge(0,5);
    add_edge(1,0);
    add_edge(1,3);
    add_edge(2,0);
    add_edge(2,3);
    add_edge(2,4);
    add_edge(3,1);
    add_edge(3,2);
    add_edge(3,5);
    add_edge(4,2);
    add_edge(4,6);
    add_edge(5,0);
    add_edge(5,3);
    add_edge(5,7);
    add_edge(6,4);
    add_edge(6,7);
    add_edge(7,5);
    add_edge(7,6);
    for(int i=0;i<v.size();i++)
    {
        cout<<i<<": ";
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j];
        cout<<endl;
    }
    // for(int i=0;i<4;i++)
    //     cout<<visited[i]<<endl;
    //print_dfs(1);
    print_bfs(0);
}