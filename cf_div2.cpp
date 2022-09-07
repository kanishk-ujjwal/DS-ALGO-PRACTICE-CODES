#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int x;
        cin>>x;
        int ans[x]={};
        int endv=(x/2)*2;
        for(int i=0;i<endv;i=i+2)
        {
            ans[i+1]=i+1;
            ans[i]=i+2;
        }
        if(x%2!=0)
        {

            ans[x-1]=ans[x-2];
            ans[x-2]=x;
            //swap(ans[x-1],ans[x]);
        }
        for(int i=0;i<x;i++)
        {
        cout<<ans[i]<<" ";
        }
        cout<<endl;
        n--;
    }
    return 0;

}
