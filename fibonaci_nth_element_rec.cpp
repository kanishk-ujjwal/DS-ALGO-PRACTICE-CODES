// finding last postion of the key in the given array
#include<iostream>
using namespace std;

int lastkey(int si,int arr[],int key)
{
    if(si==7)
        return -1;
    int index=lastkey(si+1,arr,key);
    if(index!=-1)
        return index;
    else
    {

    if(arr[si]==key)
        return si;
    else
        return -1;
    }

}
int main()
{
    int arr[]={2,3,4,3,6,3,9};
    int key=3;
    int si=0;
    cout<<lastkey(si,arr,key);
}
