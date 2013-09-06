#include <cstdio>
#include <cstring >
char map[22][22];
int n,m,cnt,dir[8][2]={1,0,-1,0,0,1,0,-1,-1,-1,-1,1,1,-1,1,1},visit[22][22];
bool OK(int i,int j)
{
    if(i<0||i==n)return false;
    if(j<0||j==m)return false;
    return true;
}
void DFS(int r,int c)
{
    visit[r][c]=1;
    for(int i=0;i<8;i++)
    {
        int ii=r+dir[i][0];
        int jj=c+dir[i][1];
        if(OK(ii,jj)&&map[ii][jj]=='X')
        {
            if(visit[ii][jj]==1){
                if(i<4)cnt-=2;
            }
            else if(!visit[ii][jj]){
                cnt+=4;
                DFS(ii,jj);
            }
        }
    }
    visit[r][c]=2;
}
int main()
{
    int r,c;
    while(scanf("%d%d%d%d",&n,&m,&r,&c),n||m||r||c)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",map[i]);
        }
        r--;    c--;
        cnt=0;
        memset(visit,0,sizeof(visit));
        if(map[r][c]=='X'){cnt=4;DFS(r,c);}
        printf("%d\n",cnt);
    }
    return 0;
}
