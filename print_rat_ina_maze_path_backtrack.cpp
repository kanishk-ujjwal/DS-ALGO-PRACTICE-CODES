#include<iostream>
using namespace std;

void ratinmaze(char path[][10],int sr,int sc,int er,int ec,int sol[][10])
{

    if(sr==er and sc==ec){
            sol[sr][sc]=1;
    for(int i=0;i<=er;i++)
    {
        for(int j=0;j<=ec;j++)
        {
            cout<<sol[i][j];
        }
        cout<<endl;
    }
    cout<<"*********"<<endl;
    return;
    }
    if(sr>er or sc>ec)
        return;


    if(path[sr][sc]=='X')
    {
        //sol[sr][sc]=0;
        return;
    }
    sol[sr][sc]=1;
    ratinmaze(path,sr,sc+1,er,ec,sol);
    ratinmaze(path,sr+1,sc,er,ec,sol);
    sol[sr][sc]=0;

    return;

}

int main()
{

    int er,ec;
    cin>>er>>ec;
    char path[er][10]={0};
    for(int i=0;i<er;i++)
    {
        for(int j=0;j<ec;j++)
        {
            cin>>path[i][j];
        }
    }
    int sol[er][10]={0};
    ratinmaze(path,0,0,er-1,ec-1,sol);
}

