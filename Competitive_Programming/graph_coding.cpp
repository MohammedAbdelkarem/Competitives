#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bestio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define cy cout<<"YES"
#define cn cout<<"NO"
#define cl cout<<"\n"
#define li "\n"
#define sp " "
#define fl(begin,end) for(ll i=begin;i<end;i++)
#define rfl(begin,end) for(ll i=end-1;i>=begin;i--)
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define eh emplace_hint
#define mae *max_element
#define mie *min_element
#define rev reverse
#define tc ll tc;cin>>tc;while(tc--)
#define b() begin()
#define e() end()
vector<vector<int>>graph;     //for adjlist representation of the graph
vector<bool>vis;              //boolean list for dfs and bfs
queue<int>q;                  //for bfs
stack<int>st;                 //for dfs
vector<int>color;             //for cycle detection
//note:we can use any data structure to achieve the logic of dfs and bfs, not just queue or stack
//the logic of bfs: visit all the neighbours one by one, then visit the neighbours of all of them one by one and so on,so in list it works like:(list.front() / list.pop_front() / list.push_back())
//the logic of dfs: visit the node then its first neighbour, then the first neighbour of this neighbour and so on,so int vector it works like:(v.back() / v.pop_back() / v.push_back())
void create_graph_nodes(int size)
{
    graph.resize(size);
    vis.resize(size , false);
    color.resize(size , 0);
}
void reset(int size)
{
    vis.resize(size , 0);
}
void reset_color(int size)
{
    color.resize(size , false);
}
void add_edge_undirected(int node1 , int node2)
{
    graph[node1].pb(node2);
    graph[node2].pb(node1);
}
void add_edge_directed(int node1 , int node2)
{
    graph[node1].pb(node2);
}
void print_graph_representation()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"==> ";
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<sp;
        cl;
    }
}
void print_BFS(int node)        //prefered to achieve it iteratively
{
    vis[node] = 1;
    q.push(node);
    while(q.size())
    {
        cout<<q.front()<<sp;
        for(int i=0;i<graph[q.front()].size();i++)
        {
            if(!vis[graph[q.front()][i]])
            {
                q.push(graph[q.front()][i]);
                vis[graph[q.front()][i]] = 1;
            }
        }
        q.pop();
    }
}
void print_DFS(int node)        //prefered to achieve it recursively
{
    if(!vis[node])
    {
        vis[node] = 1;
        cout<<node<<sp;
        for(int i=0;i<graph[node].size();i++)
            if(!vis[graph[node][i]])
                print_DFS(graph[node][i]);
    }
}
void print_dfs_iter(int node)
{
    st.push(node);
    vis[node] = 1;
    while(st.size())
    {
        cout<<st.top()<<sp;
        int s = st.top();
        st.pop();
        for(int i=0;i<graph[s].size();i++)
        {
            if(!vis[graph[s][i]])
            {
                vis[graph[s][i]] = 1;
                st.push(graph[s][i]);
            }
        }
    }
}
//dfs_bfs helper to make sure that we visit all the nodes in the graph, it will be useful in the disconnected graph(where there is a node or component not reachable from the other nodes or separated from them)
void dfs_helper()
{
    for(int i=0;i<vis.size();i++)
        if(!vis[i])
            print_DFS(i);
}
void bfs_helper()
{
    for(int i=0;i<vis.size();i++)
        if(!vis[i])
            print_BFS(i);
}
bool is_cycle_component(int node)
{
    color[node] = 1;
    for(int i=0;i<graph[node].size();i++)
    {
        if(color[graph[node][i]] == 1)
            return true;
        if(color[graph[node][i]] == 0 and is_cycle_component(graph[node][i]))
            return true;
    }
    color[node] = 2;
    return false;
}
bool is_cyclic_graph(int size)
{
    reset_color(size);
    for(int i=0;i<size;i++)
        if(color[i] == 0)
            if(is_cycle_component(i))
                return true;
    return false;
}
int main()
{
    create_graph_nodes(4);
    add_edge_directed(0,1);
    //add_edge_directed(0,2);
    //add_edge_directed(1,2);
    add_edge_directed(1,3);
    add_edge_directed(3,3);
    add_edge_directed(2,0);
    print_graph_representation();
    print_DFS(0);
    dfs_helper();
}