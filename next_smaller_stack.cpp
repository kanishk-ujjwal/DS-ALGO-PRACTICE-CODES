#include<bits/stdc++.h>
using namespace std;

void helper(int arr[],int n)
{
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() and arr[i]<s.top())
        {
            int val=s.top();
            s.pop();
            int ans[val]=arr[i];
        }
        s.push(i);
        while(!s.empty())
        {
            int val=s.top();
            s.pop();
            int ans[val]=-1;
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    helper(arr,n);
}
