#include<bits/stdc++.h>
using namespace std;
#define ROW 10
#define COL 10
int mat[ROW][COL];


int gridPath(int row,int col)
{
    for(int i=0;i<row;i++)mat[i][0]=1;
    for(int i=0;i<col;i++)mat[0][i]=1;

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            mat[i][j]=mat[i-1][j]+mat[i][j-1]+mat[i-1][j-1];
        }
    }

    return mat[row-1][col-1];
}

int main()
{
    cout<<gridPath(3,3)<<endl;
    return 0;
}
