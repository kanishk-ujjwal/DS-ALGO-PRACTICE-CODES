#include<iostream>
using namespace std;

int helper(int n)
{
    if(n==2)
        return 2;
    if(n==3)
    return 4;
    int alone=helper(n-1);
    int paired=(n-1)*helper(n-2);
    int total=alone+paired;
    return total;
}
int main()
{
    int n;
    cin>>n;
    cout<<helper(n);
}
