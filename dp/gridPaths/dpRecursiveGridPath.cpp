#include<bits/stdc++.h>
using namespace std;
#define ROW 10
#define COL 10
int mat[ROW][COL];

void init()
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)mat[i][j]=-1;
    }
}

//1 based index
int gridPath(int i,int j)
{
    if(i<1 || j<1)return 0;
    if(i>3 || j>7)return 0;
    if(i==3 && j==7)return 1;
    if(mat[i][j]!=-1)return mat[i][j];
    int right = gridPath(i,j+1);
    int below=gridPath(i+1,j);
    int diagonal=gridPath(i+1,j+1);
    int ans=right+below+diagonal;
    mat[i][j]=ans;
    return mat[i][j];
}


//0 based index
int gridPath2(int i,int j)
{
    if(i<0 || j<0)return 0;
    if(i>2 || j>6)return 0;
    if(i==2 && j==6)return 1;
    if(mat[i][j]!=-1)return mat[i][j];
    int right = gridPath2(i,j+1);
    int below=gridPath2(i+1,j);
    int diagonal=gridPath2(i+1,j+1);
    int ans=right+below+diagonal;
     mat[i][j]=ans;
    return mat[i][j];
}

//top down approach
int gridPath3(int i,int j)
{
    if(i<0 || j<0)return 0;
    if(i>2 || j>6)return 0;
    if(i==0 && j==0)return 1;
    if(mat[i][j]!=-1)return mat[i][j];
    int right = gridPath3(i,j-1);
    int below=gridPath3(i-1,j);
    int diagonal=gridPath3(i-1,j-1);
    int ans=right+below+diagonal;
     mat[i][j]=ans;
    return mat[i][j];
}

int main()
{
    init();
    //1 based index
    cout<<gridPath(1,1)<<endl;
    init();
    //0 based index
    cout<<gridPath2(0,0)<<endl;
    init();
    //top down approach
    cout<<gridPath3(2,6)<<endl;
    return 0;
}

