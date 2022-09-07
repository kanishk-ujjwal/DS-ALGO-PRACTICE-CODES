#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N];
int vis[N];
void dfs( int curr)
{
    //cout<<curr<<endl;
    vis[curr]=1;

    for(auto x:adj[curr])
    {
        if(!vis[x])
            dfs(x);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x;
        cin>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int connected=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            connected++;
        }
    }
    cout<<connected<<endl;
}
