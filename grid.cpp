
#include<bits/stdc++.h>
using namespace std;

int maxRow;
int maxCol;

int rc[4]= {1,0,-1,0};
int cc[4]={0,1,0,-1};

bool checkGrid(int r,int c)
{
    if(r<0 || c<0) return false;
    if(r>maxRow || c>maxCol) return false;
    return true;
}

void island(vector<vector<int>>grid)
{
    maxRow=grid.size()-1;
    maxCol=grid[0].size()-1;
    for(int row=0;row<grid.size();row++)
    {
        for(int col=0;col<grid[row].size();col++)
        {
            if(grid[row][col]==1)
            {
                cout<<"\tHome grid"<<" row: "<<row<<" "<<"col: "<<col<<endl;
                cout<<"Neighbor grid indexes are: "<<endl;
                for(int index=0;index<4;index++)
                {
                    int newRow=row+rc[index];
                    int newCol=col+cc[index];
                    if(checkGrid(newRow,newCol))
                    {
                        cout<<"Valid grid: "<<newRow<<" "<<newCol<<endl;
                    }
                    else
                    {
                        cout<<"Invalid grid: "<<newRow<<" "<<newCol<<endl;
                    }
                }
            }
        }
    }
}

void printGrid(vector<vector<int>>grid)
{
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    //printEven();

    vector<vector<int>>v1={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    vector<vector<int>>v2={{1}};
    printGrid(v1);
    island(v1);
    return 0;
}


