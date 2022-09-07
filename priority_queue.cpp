#include <bits/stdc++.h>
using namespace std;

struct heap{
    vector<int> a;
 heap(vector<int>v)
 {
     a=v;
 }

 void heapify(int indx)
 {
     int left=2*indx+1;
     int right=2*indx+2;
     int minindx=indx;
     if(left<a.size() and a[left]<a[minindx])
     {
         minindx=left;
     }
     if(right<a.size() and a[right]<a[minindx])
     {
         minindx=right;
     }
     if(minindx!=indx)
     {
         swap(a[indx],a[minindx]);
        heapify(minindx);
     }
     return;
 }
 void build_heap()
 {
     int last_parent=(a.size()-2)/2;
     for(int i=last_parent;i>=0;i--)
     {
         heapify(i);
     }
 }
 int top()
 {
     return a[0];
 }
 bool empty()
 {
     return a.empty();
 }
 void clear()
 {
     a.clear();
 }
 void pop()
 {
     int lastindx=a.size()-1;
     swap(a[0],a[lastindx]);
     a.pop_back();
     heapify(0);
 }
 void push(int val)
 {
     a.push_back(val);
     int indx=a.size();
     int parent=(indx-1)/2;
     while(indx>=0 and a[parent]>a[indx])
     {
         swap(a[indx],a[parent]);
         indx=parent;
         parent=(indx-1)/2;
     }
 }

};
void heapsort(vector<int> a)
{
    heap H(a);
    H.build_heap();
    for(int i=0;i<a.size();i++)
    {
        cout<<H.top()<<endl;
        H.pop();
    }

}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
 heap H(v);
 H.build_heap();
 cout<<H.top()<<endl;
 H.pop();
 H.push(0);
 cout<<H.top()<<endl;
 heapsort(v);
}
