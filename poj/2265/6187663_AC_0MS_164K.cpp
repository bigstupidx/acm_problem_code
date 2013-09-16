#include <cstdio>
#include <cstring>
int dir[6][2]={-1,1,-1,0,0,-1,1,-1,1,0,0,1};
void solve(int n)
{
    int tem=1,fi=1;
    while(tem+fi*6<=n){tem+=fi*6;fi++;}
    if(tem==n){printf("%d 0\n",fi-1);return;}
    //tem-=(fi-1)*6;
    int x=fi,y=0;
    //printf("%d %d %d\n",x,y,fi);
    int k=0;
    while(tem+fi<=n)
    {
        x+=fi*dir[k][0];
        y+=fi*dir[k][1];
        k++; tem+=fi;
    }
    printf("%d %d\n",x+(n-tem)*dir[k][0],y+(n-tem)*dir[k][1]);
}
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
        solve(n);
    return 0;
}
