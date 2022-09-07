#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char> a;
    int i=0;
    while(i<s.length())
    {
        if(s[i]==')')
        {
            if(a.top()=='(')
            {
                cout<<"false"<<endl;
                return false;
            }
            else
            {
                while(a.top()!='(')
                {
                    a.pop();
                }
                a.pop();
            }
        }
        a.push(s[i]);
        i++;
    }
    cout<<"true"<<endl;
    return true;
}
