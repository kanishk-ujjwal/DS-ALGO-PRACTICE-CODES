#include<bits/stdc++.h>
using namespace std;
// stl functions discusseed;
//array
int main()
{
    // for triplets
    pair<int,pair<int,int>>c={1,{2,3}};

    pair<int,int>arr[]={{1,2},{2,3},{4,5}};
    cout<<arr[1].second<<endl;
    // To copy vector v1 to v2
    vector<int>v1(5,20);
    vector<int>v2(v1);
    vector<int>v3={10,20,30,40};
    vector<int>::iterator it=v3.begin();
    cout<<*(it)<<endl;
    it++;
    cout<<*it<<endl;
    // v.end() points to the next memory of the last element ie null
    //v.rend() where r->reverse which points to the pointer before begin() but rbegin() points to the last element only;
    // iterator=v3.cbegin() where c-> constant which means that the iterator won't move even if i do it++;
    for(auto it:v3) // auto gets converted to integer
    cout<<it<<endl; // prints the elements;
    for(auto it=v3.begin();it!=v3.end();it++)// here auto gets converted to a pointer as .begin() functions gives a pointer
    cout<<*it<<endl; // *pointer-> gives the value to which the pointer is pointing to;

    v3.erase(v3.begin()+2);// v.erase(pointer); or for a range of values v.erase(v3.begin()+2, v3.begin()+4) [start,end);
    v3.insert(v.begin(),300); // v.insert(pointer pointing to pos, element) or (pointer, no of times element, element)
    //or v.insert(pointer, v2.begin(), v2.end()); copies v2 to v;
    //int indx=lower_bound(v.begin(),v.end(),x)-v.begin(); indx gets the lower bound if DNE then gets the next largest element;
    // if(indx<n&& v[indx]==x) return indx; else return -1;
    // int indx=upper_bound(v.begin(),v.end(),x-v.begin()); indx gets the next higher element if the element exits or DNE ; Therefore->indx--;
    // if(indx>=0 && v[indx]==x) return indx; else return -1;
    //priority_queue<int>x;// maxheap
    priority_queue<int,vector<int>, greater<int>> x;// minheap



}
