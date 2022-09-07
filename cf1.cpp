#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        double n,x,t;
        cin>>n>>x>>t;
    double time=t;
    double sum=0;
    double tt=(n-1)*x;
    if(time>=tt)
    {
        sum=(n*(n-1))/2;
    }
    else
    {
    for(int i=0;i<n;i++)
    {
        int res=(int)time/x;
            sum+=res;
            sum=sum-i;
            if(time<tt)
            {
            time+=x;
            }
    }
    }
    cout<<setprecision(20)<<sum<<endl;
    }
}
