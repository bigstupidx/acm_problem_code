#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
struct node{
    int x,y;
}que[102],kni[102];
int m,n,map[1002][1002],n1,n2,n3;
int dir[8][2]={0,-1,0,1,-1,0,1,0,-1,-1,-1,1,1,-1,1,1};
bool OK(int i,int j)
{
    if(i<0||i==n||j<0||j==m)return false;
    return true;
}
int main()
{
    int nca=1;
    while(scanf("%d%d",&n,&m),n||m)
    {
        int x,y;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                map[i][j]=0;
        
        scanf("%d",&n1);
        for(int i=0;i<n1;i++){
            scanf("%d%d",&x,&y);
            x--;    y--;
            map[x][y]=2;
            que[i].x=x; que[i].y=y;
        }
        scanf("%d",&n2);
        for(int i=0;i<n2;i++){
            scanf("%d%d",&x,&y);
            x--;    y--;
            map[x][y]=2;
            kni[i].x=x; kni[i].y=y;
        }
        scanf("%d",&n3);
        for(int i=0;i<n3;i++){
            scanf("%d%d",&x,&y);
            x--;y--;
            map[x][y]=2;
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<8;j++){
                x=que[i].x; y=que[i].y;
                while(1){
                    x+=dir[j][0];
                    y+=dir[j][1];
                    if(OK(x,y)){
                        if(map[x][y]==2)break;
                        map[x][y]=1;
                    }
                    else break;
                }
            }
        }
        for(int i=0;i<n2;i++){
            for(int j=4;j<8;j++){
                int ii=kni[i].x+dir[j][0];
                int jj=kni[i].y+dir[j][1];
                if(OK(ii,jj)&&map[ii][jj]==0){
                    map[ii][jj]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]==0)
                    ans++;
        printf("Board %d has %d safe squares.\n",nca++,ans);
    }
    return  0;
}
