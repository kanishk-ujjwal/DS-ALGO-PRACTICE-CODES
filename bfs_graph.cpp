#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>grph[N];
int vis[N];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int curr=q.front();
        cout<<curr<<"->";
        q.pop();
        for(auto x: grph[curr])
        {
            if(!vis[x])
            {
                vis[x]=1;
                q.push(x);
            }
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        grph[x].push_back(y);
        grph[y].push_back(x);
    }
    bfs(9);

}

