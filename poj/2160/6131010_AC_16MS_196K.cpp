#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
    int x, y;
    bool operator<(const node a)const
    {
        if(a.x==x)return  a.y>y;
        return a.x>x;
    }
}nod[6];
int arrey[20];
bool solve()
{
    sort(nod,nod+6);
    //for(int i=0;i<6;i++)
    //    printf("%d %d\n",nod[i].x,nod[i].y);
    for(int i=0;i<3;i++)
    {
        if(nod[2*i].x!=nod[2*i+1].x)return false;
        if(nod[2*i].y!=nod[2*i+1].y)return false;
    }
    int k=0;
    for(int i=0;i<6;i++)
    {
        arrey[k++]=nod[i].x;
        arrey[k++]=nod[i].y;
    }
    sort(arrey,arrey+12);
    for(int i=0;i<3;i++)
    {
        if(arrey[i*4+1]!=arrey[i*4])return false;
        if(arrey[i*4+2]!=arrey[i*4])return false;
        if(arrey[i*4+3]!=arrey[i*4])return false;
    }
    //for(int i=0;i<12;i++)
    //    printf("%d ",arrey[i]);
    //puts("");
    return true;
}
int main()
{
    for(int i=0;i<6;i++)
    {
        int x,y,tem;
        scanf("%d%d",&x,&y);
        if(x>y)tem=x,x=y,y=tem;
        nod[i].x=x; nod[i].y=y;
    }
    if(solve())puts("POSSIBLE");
    else puts("IMPOSSIBLE");
    
    system("pause");
    return  0;
}
