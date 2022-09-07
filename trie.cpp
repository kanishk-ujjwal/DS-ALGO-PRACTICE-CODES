#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    char d;
    unordered_map<char,node*>children;
    unordered_map<char,int>m;
    bool terminal;
    node(char ch)
    {
        d=ch;
        terminal=false;
    }
};

class trie
{
public:
    node* root;
    int cnt;

    trie()
    {
        root=new node('\0');
        cnt=0;
    }

    void insert(char *w)
    {
        node *temp= root;
        for(int i=0;w[i]!='\0';i++)
        {
            if(temp->children.count(w[i]))
            {
                temp=temp->children[w[i]];
            }
            else
            {
                node *n=new node(w[i]);
                temp->children[w[i]]=n;
                temp=n;
            }
            temp->m[w[i]]++;
        }
        temp->terminal=true;
    }
    bool find(char* w)
    {
        node* temp=root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch=w[i];
            if(temp->children.count(ch)==0)
                return false;
            else
                temp=temp->children[ch];
        }
        return temp->terminal;
    }
    void prefix()
    {
        for(int i=0;i<5;i++)
    {
        char ans[10]={};
        int flag=0;
        for(int j=0;words[i][j]!='\0';j++)
        {
            char x=words[i][j];

            if(m[x]!=1)
            {
                ans[j]=words[i][j];
            }
            else
            {
                for(int q=0;q<j;q++)
                {
                    cout<<ans[q];
                }
                flag=1;
                break;
            }

        }
        if(flag==0)
            cout<<"DNE"<<endl;
    }
    }

};
int main()
{
    trie t;
    char words[][10]={"abc","not","no","new","a"};
    char s[10];
    cin>>s;
    for(int i=0;i<5;i++)
    {
        t.insert(words[i]);
    }
    t.prefix();
}
