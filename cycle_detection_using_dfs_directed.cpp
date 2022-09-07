#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N];
int vis[N];
bool cycle;
// 0-> not visited
//1-> visited and in call stack;
// 2-> visited and not in call stack
void dfs( int curr)
{
    vis[curr]=1;
    for(auto x:adj[curr])
    {
        if(vis[x]==0)
            dfs(x);
        else if(vis[x]==1)
            cycle=1;
    }
    vis[curr]=2;

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
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    cout<<cycle<<endl;
    return 0;
}
