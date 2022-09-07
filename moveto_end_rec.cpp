#include<iostream>
using namespace std;

string helper(string s)
{
    if(s.length()==0)
        return "";
    char ch=s[0];
    string ros=s.substr(1);
    string sub=helper(ros);
    if(ch=='x')
        return sub+ch;
        else
            return ch+sub;

}
int main()
{
    cout<<helper("xaxbxc")<<endl;
}
