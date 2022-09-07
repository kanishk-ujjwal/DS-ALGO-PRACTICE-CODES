#include<iostream>
using namespace std;

string helper(string str)
{
    if(str.length()==0)
        return str;
    char ch=str[0];
    string ros=str.substr(1);
    string sub=helper(ros);
    if(ch==sub[0])
        return ch+(string)"*"+sub;
    else
    return ch+sub;
}
int main()
{
    cout<<helper("abbcddefg")<<endl;
}

