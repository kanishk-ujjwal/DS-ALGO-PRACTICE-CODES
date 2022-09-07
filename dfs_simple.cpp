#include<bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<int>adj[], bool visited[])
{
    cout<<curr<<endl;
    visited[curr]=true;
    for(auto x:adj[curr])
    {
        if(visited[x]==false)
            dfs(x,adj,visited);
    }
}
int main()
{
    int n;
    cin>>n;
    //int m; cin>>m; // in case of a graph m is storing no of edges;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++) // i<m for graph (edges)
    {
        int x,y;
        cin>>x;
        cin>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool visited[n+1];
    int root=1;
    dfs(root, adj, visited);

}
