#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N];
int vis[N];
bool cycle;
void dfs( int curr,int par)
{
    vis[curr]=1;
    for(auto x:adj[curr])
    {
        if(vis[x]==0)
            dfs(x,curr);
        else if(x!=par)
        cycle=1;
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
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,0);
    }
    cout<<cycle<<endl;
    return 0;
}
