#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int freq[256]={0};
    queue<char>q;
    q.push(s[0]);
    cout<<s[0];
    freq[s[0]]++;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==q.front())
        {
            q.pop();
            if(q.empty())
            {
                cout<<"-1";
            }
            else
            {
                cout<<q.front();
            }
        }
        else
        {
            q.push(s[i]);
            cout<<q.front();
        }

    }
}
