#include<iostream>
using namespace std;

int helper(int a[],int n,int key)
{
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==key)
        {
            ans=mid;
            //end=mid-1;
        }
        if(a[mid]>=key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[n]={0};
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cin>>key;
    cout<<helper(a,n,key)<<endl;
    return 0;
}
