#include<iostream>
using namespace std;

int helper(int start,int endv)
{
    if(start==endv)
        return 1;
    if(start>endv)
        return 0;

    int countv=0;

    for(int jump=1;jump<=6;jump++)
    {
         countv+=helper(start+jump,endv);
    }
    return countv;
}
int main()
{
    int start=0;
    int endv=10;
    cout<<helper(start,endv)<<endl;
}
