#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t!=0)
    {
        int n;
        cin>>n;
        ll ans[n+1]={};
        for(ll i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            ans[i]=x;
        }
        ll count=0;
        for(ll i=1;i<n;i++)
        {
            ll j=ans[i]-i;
            while(j<=n)
            {
                if(j>i and ans[j]*ans[i]==i+j)
                count++;
                j=j+ans[i];
            }
        }
        cout<<count<<endl;
        t--;
    }
}
