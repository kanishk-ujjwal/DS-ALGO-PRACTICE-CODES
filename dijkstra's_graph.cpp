#include <bits/stdc++.h>
// Single source shortest path
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

vector<int> dij(int src, int n)
{
    vector<int>dis(n+1,0);
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0,src});
    while(!q.empty())
    {
        p var=q.top();
        q.pop();

        int curr=var.second;
        int currdis=var.first;

        if(!vis[curr])
        {
            vis[curr]=1;
            dis[curr]=currdis;
            for(auto to:grph[curr])
            {
                int ele=to.second;
                int wt=to.first;
                if(!vis[ele])
                q.push({dis[curr]+wt,ele});
            }
        }
        cout<<"while"<<endl;


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
    vector<int> dis=dij(1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<"dist of"<<i<<"->"<< dis[i]<<endl;
    }
}
