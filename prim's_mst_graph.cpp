#include <bits/stdc++.h>
// minimum spanning tree
using namespace std;
const int N=1e5;
#define p pair<int,int>
vector<p>grph[N];
int vis[N];

struct mycomp
{
    bool operator()(p &a, p &b)
    {
        return a.first>b.first;
    }
};

int dij(int src, int n)
{
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0,src});
    int mst=0;
    while(!q.empty())
    {
        p var=q.top();
        q.pop();

        int curr=var.second;
        int currdis=var.first;

        if(!vis[curr])
        {
            vis[curr]=1;
            mst+=currdis;
            for(auto to:grph[curr])
            {
                int ele=to.second;
                int wt=to.first;
                if(!vis[ele])
                q.push({wt,ele});
            }
        }


    }
    return mst;

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
        grph[y].push_back({x,w});
    }
    int dis=dij(1,n);
    cout<<dis;

}
