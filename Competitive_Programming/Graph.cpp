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
int n,e;
vector<bool>vis={0};
vector<vector<int,int>>arrayoflists(n);
void dfs(int node)
{
    vis[node]=1;
    cout<<node<<sp;
    for(int i=0;i<arrayoflists.size();i++)
    {
        for(int j=0;j<arrayoflists[i].size();j++)
        {
            if(!vis[arrayoflists[i][j]])
                dfs(arrayoflists[i][j]);
        }
    }
}
int main()
{
    //we will write some diferrent representations of the graph, regardless if it is directed  or undirected graph
    /*
    represent unweighted graph:(bool relationshp)
    input:  n: number of nodes , e : number of edges ,  then the next e lines the edge from x to y
        for ex:
        5 6 
        1 3
        2 4
        1 5
        3 2
        5 3
        2 1
    */
    // as an adjacency matrix:
    int adjmatrix[n][n] = {0};
    while(e--)
    {
        int x,y;cin>>x>>y;
        adjmatrix[x][y] = 1;
    }
    // as an adjacency list:
    vector<vector<int>>v(n , vector<int>(n , 0));                                   // initialize the vector with zero
    while(e--)
    {
        int x,y;cin>>x>>y;
        v[x].pb(y);
    }


    /*
    represent weighted graph:(cost relationship)
    input:  n: number of nodes , e : number of edges ,  then the next e lines the edge from x to y and the cost of the edge
        for ex:
        5 6 
        1 3 4
        2 4 6
        1 5 7
        3 2 13 
        5 3 2
        2 1 3
    */
   // as an adjacency matrix:
    int adjmatrix[n][n] = {0};
    while(e--)
    {
        int x,y,cost;cin>>x>>y;
        adjmatrix[x][y] = cost;
    }
    // as an adjacency list:
    vector<vector<pair<int,int>>>vv(n);
    while(e--)
    {
        int x,y,cost;cin>>x>>y>>cost;
        vv[x].pb({y,cost});
    }
}
