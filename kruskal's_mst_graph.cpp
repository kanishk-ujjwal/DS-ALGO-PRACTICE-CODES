#include <bits/stdc++.h>
// minimum spanning tree
using namespace std;
const int N=1e5;
#define p pair<int,int>
vector<pair<int,p>>grph;
vector<p> ele;
int vis[N];
int parent[N];
int ranks[N];

struct mycomp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0]>b[0];
    }
};
void make_set(int x)
{
    parent[x]=x;
    ranks[x]=1;
}
int find_set(int x)
{
    if(parent[x]==x)
        return x;
    return find_set(parent[x]);
}
void union_set(int x, int y)
{
    int a=find_set(x);
    int b=find_set(y);
    if(a!=b)
    {
        if(ranks[b]>ranks[a])
            swap(b,a);
        parent[b]=a;
        ranks[a]+=ranks[b];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        make_set(i);
    }
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        grph.push_back({w,{x,y}});
    }
    int ans=0;
    sort(grph.begin(), grph.end());
    for(int i=0;i<m;i++)
    {
        int wt=grph[i].first;
        int from=grph[i].second.first;
        int to=grph[i].second.second;
        if(find_set(from)!=find_set(to))
        {
            ans+=wt;
            ele.push_back({from,to});
            union_set(from,to);
        }
        cout<<ans<<endl;
        for(int i=0;i<ele.size();i++)
        {
            cout<<ele[i].first<<"->"<<ele[i].second;
        }
    }
}
