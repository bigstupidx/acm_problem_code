#include <cstdio>
#include <cstring>
int map[30][30],closed[30],n;
const int inf=1000000000;
int Prim()
{
    int ans=0;
    for(int i=0;i<n;i++)
        closed[i]=map[0][i];
    for(int i=1;i<n;i++)
    {
        int k,mini=inf;
        for(int j=1;j<n;j++)
            if(closed[j]&&mini>closed[j])
                mini=closed[j],k=j;
        ans+=mini;
        closed[k]=0;
        for(int j=1;j<n;j++)
            if(closed[j]&&closed[j]>map[k][j])
                closed[j]=map[k][j];
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        char aa[4];
        int d,m;  getchar();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                map[i][j]=inf;
        for(int i=0;i<n;i++)map[i][i]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%s%d",aa,&m);
            for(int j=0;j<m;j++)
            {
                scanf("%s%d",aa,&d);
                map[i-1][aa[0]-'A']=d;
                map[aa[0]-'A'][i-1]=d;
            }
            getchar();
        }/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",map[i][j]);
            puts("");
        }*/
        printf("%d\n",Prim());
    }
    return 0;
}
