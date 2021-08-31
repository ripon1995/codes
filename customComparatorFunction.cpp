#include<bits/stdc++.h>
using namespace std;


struct Point
{
    int x,y;
};

bool cmp(Point A, Point B)
{
    if(A.x<B.x)return true;
    if(A.x>B.x)return false;

    if(A.y<B.y)return true;
    if(A.y>B.y)return false;

    return false;
}

bool comparator(Point A,Point B)
{
    if(A.x!=B.x)return A.x<B.x;
    return A.y<B.y;
}

int main()
{
    Point p[4];

    p[0].x=100;p[0].y=20;

    p[1].x=15;p[1].y=30;

    p[2].x=15;p[2].y=40;

    p[3].x=2;p[3].y=30;

    for(int i=0;i<4;i++)
    {
        cout<<p[i].x<<" "<<p[i].y<<endl;
    }

    //sort(p,p+4,cmp);
    sort(p,p+4,comparator);

    cout<<"After sorting: "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<p[i].x<<" "<<p[i].y<<endl;
    }

    return 0;
}

