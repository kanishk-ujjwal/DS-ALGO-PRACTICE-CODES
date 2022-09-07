#include<iostream>
using namespace std;

int helper(int sr,int sc, int er,int ec)
{
    if(sr==sr and sc==ec)
        return 1;
    if(sr>er or sc>ec)
        return 0;
    int movedown=helper(sr+1,sc,er,ec);
    int moveright=helper(sr,sc+1,er,ec);
    int total=movedown+moveright;
    return total;
}
int main()
{
    cout<<helper(0,0,3,3)<<endl;
}

