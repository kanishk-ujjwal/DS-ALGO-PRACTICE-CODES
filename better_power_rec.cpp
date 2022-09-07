#include<iostream>
using namespace std;

int power(int n)
{
    if(n==0)
        return 1;
    int subprob=power(n/2);
    //for even power
    if(n%2==0){
    int ans=subprob*subprob;
    return ans;
    }
    //for odd power
    else{
    int ans=2*subprob*subprob;
    return ans;}
}
int main()
{
    int n;
    cin>>n;
    cout<<power(n)<<endl;
}
