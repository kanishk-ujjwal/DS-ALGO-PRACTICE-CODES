#include<bits/stdc++.h>
using namespace std;

bool helper(int a[], int n)
{
    unordered_set<int>s;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(s.find(pre)!=s.end() or pre==0)
            return true;
        s.insert(pre);
    }
    return false;
}
int main()
{

    int n;
    cin>>n;
    int a[n]={};
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<helper(a,n)<<endl;
    return 0;
}
