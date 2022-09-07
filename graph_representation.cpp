#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>grph[n+1];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        grph[x].push_back(y);
        grph[y].push_back(x); // for undirected grph
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto z: grph[i])
        cout<<z<<" ";
        cout<<endl;
    }

    // for weighted graph
    //vector<int,int>graph[n+1];
//    for(int i=0;i<n;i++)
//    {
//        int x,y,w;
//        cin>>x>>y>>w;
//        grph[x].push_back({y,w});
//        grph[y].push_back({x,w}); // undirected grph
//    }

        //EDGE LIST REPRESENTATION
//    vector<pair<int,int>> edges(n);
//    for(int i=0;i<n;i++)
//    {
//        cint>>edges[i].first>>edges[i].second;
//    }
// for(auto x:edges)
// {
//     cout<<x.first<<"->"<<x.second<<endl;
// }
}
