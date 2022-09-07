#include <bits/stdc++.h>
using namespace std;
int rec(int start,int mysum,int end)
    {
        if(mysum==end)
        return 0;
        int count1=INT_MAX;
        int count2=INT_MAX;
        count1=rec(start+1,mysum+start,end);
        count2=rec(start+2,mysum+start,end);
        int minval=min(count1,count2);
        return minval+1;
    }
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int sum;
        cin>>sum;
        int i=1;
        int mysum=0;
        cout<<rec(i,mysum,sum)<<endl;
    }
    return 0;
}

