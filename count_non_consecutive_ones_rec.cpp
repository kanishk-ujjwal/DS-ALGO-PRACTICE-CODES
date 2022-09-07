#include<iostream>
using namespace std;

int helper(int n)
{
    if(n==2 or n==1)
        return n+1;
    int withzero=helper(n-1);
    int withone= helper(n-2);
    int total=withzero+withone;
    return total;
}
int main()
{
    int n;
    cin>>n;
    cout<<helper(n);
}
