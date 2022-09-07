#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N];
int vis[N];
void dfs( int curr)
{
    cout<<curr<<endl;
    vis[curr]=1;
    for(auto x:adj[curr])
    {
        if(!vis[x])
            dfs(x);
    }
}
int par_list[N];
void dfs_tree(int curr,int par)
{
    cout<<curr<<"->";
    par_list[curr]=par;
    for(auto child:adj[curr])
    {
        if(child!=par)
            dfs_tree(child,curr);

    }
    cout<<endl;

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
    dfs_tree(5,0);
    for(int i=1;i<=n;i++)
    {
        int curr=i;
        cout<<curr<<"->";
        while(curr!=0)
        {
            cout<<curr;
            curr=par_list[curr];
        }
        cout<<endl;
    }
}
