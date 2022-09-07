#include<iostream>
using namespace std;

bool issafe(int col,int row,int board[][4])
{
    for(int i=row;i>=0;i--)
    {
        if(board[i][col]==1)
            return false;
    }
    int x=row;
    int y=col;
    while(x>=0 and y>=0)
    {
        if(board[x][y]==1)
            return false;
        else
        {
            x--;
            y--;
        }
    }
    x=row;
    y=col;
    while(x>=0 and y<4)
    {
        if(board[x][y]==1)
            return false;
        else
        {
            x--;
            y++;
        }
    }
    return true;
}
int helper(int board[][4],int n,int row)
{
    if(row==n)
    {
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                if(board[i][j]==1)
//                    cout<<"q ";
//                else
//                    cout<<"_ ";
//            }
//            cout<<endl;
//        }
//        cout<<"************"<<endl;
        return 1;
    }
    int count=0;
    for(int col=0;col<n;col++)
    {
        if(issafe(col,row,board))
        {
            board[row][col]=1;
            count+=helper(board,n,row+1);
//            if(subprob==1)
//                return true;
 //           else
                board[row][col]=0;

        }
    }
    return count;
}
int main()
{
    int board[4][4]={0};
    int n=4;
    cout<<helper(board,n,0)n;
    return 0;
}

