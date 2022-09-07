#include<bits/stdc++.h>
using namespace std;
class dsu{
    public:
        vector<int>par;
    dsu(int n)
    {
        par.resize(n+1);
        iota(par.begin(),par.end(),0);
        // for(int i=0;i<=n;i++)
        //{ par[i]=i;}
    }
    int get(int x)
    {
        if(par[x]==x)
        return x;
        else
        return par[x]=get(par[x]);
    }
    void unite(int x, int y)
    {
        int px=get(x);
        int py=get(y);
        if(px!=py)
        {
            par[x]=y;
        }
    }

};
int main(int A, vector<vector<int>>& B) {
    vector<vector<int>> edges(B.size());
    int mst=0;
    for(int i=0;i<B.size();i++)
    {
        edges[i]={B[i][2],B[i][0],B[i][1]};
    }
    dsu Q(A);
    sort(edges.begin(),edges.end());
    for(int i=0;i<B.size();i++)
    {
        int x=edges[i][1];
        int y=edges[i][2];
        int wt=edges[i][0];
        if(Q.get(x)!=Q.get(y))
        {
            mst+=wt;
            Q.unite(x,y);
        }

    }
    return mst;
}

