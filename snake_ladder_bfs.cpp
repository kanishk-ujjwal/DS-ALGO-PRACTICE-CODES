#include <bits/stdc++.h>
using namespace std;
const int N=100;
vector<int>grph[N+1];
vector<int>bfs(int source, int n)
{
int vis[N+1]={0};
vector<int>dis(n+1,0);
queue<int>q;
q.push(source);
vis[source]=1;
dis[source]=0;
while(!q.empty())
{
    int curr=q.front();
    q.pop();
    for(auto x:grph[curr])
    {
        if(!vis[x])
        {
            vis[x]=1;
            dis[x]=dis[curr]+1;
            q.push(x);
        }
    }
}
return dis;
}

int snake(vector<vector<int> > &A, vector<vector<int> > &B) {
    int board[101]={0};
    cout<<76<<endl;
    for(int i=0;i<A.size();i++)
    {
        int x=A[i][0];
        int jump=A[i][1]-x;
        board[x]=jump;
    }
    for(int i=0;i<B.size();i++)
    {
        int x=A[i][1];
        int jump=A[i][0]-x;
        board[x]=jump;
    }
    for(int i=1;i<=100;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
           int j=i+dice;
            j=j+board[j];
            if(j<=100)
            {
                grph[i].push_back(j);
            }
        }
    }
    cout<<78<<endl;
    grph[100].push_back(100);
    vector<int> ans= bfs(1,100);
    return ans[100];
}
int main()
{
    vector<vector<int>>A;
    vector<vector<int>>B;
   // cout<<4<<endl;
    int n1,n2;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++)
    {
        cin>>A[i][0]>>A[i][1];
    }
    for(int i=0;i<n2;i++)
    {
        cin>>B[i][0]>>B[i][1];
    }
    cout<< snake(A,B)<<endl;
}
