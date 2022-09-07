#include <bits/stdc++.h>
// Single source shortest path for neagative edges
using namespace std;
const int N=1e5;
#define p pair<int,int>
vector<p>grph[N];
int vis[N];

vector<int> bell(int src,int n)
{
    vector<int> dis(n+1,INT_MAX);
    dis[src]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=grph[j][0];
            int v= grph[j][1];
            int wt=grph[j][2];
            if(dis[u]!=INT_MAX and dis[v]>dis[u]+wt)
            {
                if(step==n)
                    cout<<"-ve edge found"<<endl;
                dis[v]=dis[u]+wt;
            }
        }
    }
    return dis;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        grph[x].push_back({y,w});
    }
    vector<int> dis=bell(1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<"dist of"<<i<<"->"<< dis[i]<<endl;
    }
}
