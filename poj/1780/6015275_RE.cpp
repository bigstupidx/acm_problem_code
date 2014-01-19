#include <cstdio>
#include <cstring>
int map[10000010][10],n,nsta,k;
char ans[10000010];
void euler(int s)
{
    for(int i=0;i<10;i++)
    {
        if(map[s][i])
        {
            map[s][i]--;
            euler((s*10+i)%nsta);
            ans[k--]='0'+i;
        }
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        nsta=1;
        for(int i=1;i<n;i++)nsta*=10;
        for(int i=0;i<nsta;i++)
            for(int j=0;j<10;j++)
                map[i][j]=1;
        ans[nsta*10+n-1]=0;
        k=nsta*10+n-2;euler(0);
        for(int i=1;i<n;i++)printf("0");
        printf("%s\n",ans); 
    }
    return 0;
}
