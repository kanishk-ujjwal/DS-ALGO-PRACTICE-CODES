#include<iostream>
using namespace std;

void helper(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
    return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    helper(ros,ans);
    helper(ros,ans+ch);
}

int main()
{
    helper("abc","");
    return 0;
}
