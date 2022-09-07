#include<iostream>
using namespace std;

 string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

 void helper(string s, string ans)
 {

     if(s.length()==0)
     {

        cout<<ans<<endl;
        return;
     }

        char ch=s[0];
        string ros=s.substr(1);
        int no=ch-'0';
        string str=code[no];
        for(int i=0;i<str.length();i++)
        {
            helper(ros,ans+str[i]);
        }
 }

int main()
{
  helper("246","");
}
