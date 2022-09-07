#include<iostream>
using namespace std;

void helper(int start,int end,string ans)
{
    if (start==end)
    {
        cout<<ans<<endl;
        return;
    }
    if(start>end)
    {
        return;
    }
    for(int jump=1;jump<=6;jump++)
    {
        //string temp= to_string(jump);
        helper(start+jump,end,ans+(char)(jump+48)); // or do ans+temp

    }

}
int main()
{
    helper(0,10,"");
    return 0;
}
