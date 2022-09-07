#include <bits/stdc++.h>
using namespace std;

bool ispossible(int board[],int n,int painters,int mid)
{
    int countpainters=1;
    int time=0;
    for(int i=0;i<n;i++)
    {
        time+=board[i];
        if(time>mid)
        {
             countpainters++;
             time=board[i];
        }
        if(countpainters>painters)
            return false;
    }
    return true;
}
int helper(int board[],int n,int painters)
{
    int maxtime=0;
    int mintime=*max_element(board,board+n);
    for(int i=0;i<n;i++)
    {
        maxtime+=board[i];
    }
    int start=mintime;
    int end=maxtime;
    int ans=0;
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(ispossible(board,n,painters,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int board[n];
    for(int i=0;i<n;i++)
    {
        cin>>board[i];
    }
    int k;
    cin>>k;
    cout<<helper(board,n,k);
}
