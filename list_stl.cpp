#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> kanishk;
    kanishk.push_back(3);
    kanishk.push_front(6);
    kanishk.push_back(39);
    kanishk.push_back(89);
    kanishk.push_back(314);

    cout<<kanishk.front()<<endl;
    cout<<kanishk.back()<<endl;

    for(int val:kanishk)
    {
        cout<<val<<"->";
    }
    cout<<endl;
    kanishk.sort();
    for(int val:kanishk)
    {
        cout<<val<<"->";
    }
    cout<<endl;
    kanishk.pop_front();
    kanishk.pop_back();

    for(int val:kanishk)
    {
        cout<<val<<"->";
    }
    cout<<endl;
}
