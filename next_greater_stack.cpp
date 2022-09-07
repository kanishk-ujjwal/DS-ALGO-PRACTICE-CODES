#include <bits/stdc++.h>
using namespace std;

void helper(int arr[], int n)
{
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() and arr[i]>s.top())
        {
            int val=s.top();
            cout<<val<<"->"<<arr[i]<<endl;;
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout<<s.top()<<"-> -1"<<endl;
        s.pop();
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
    return 0;
}
