#include<cstdio>
#include<cstring>

int n,start[600],end[600],map[550][550],y[550],flag[550];
int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
bool Path(int s)
{
    for(int i=0;i<n;i++)
    {
        if(!flag[i]&&map[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    for(int i=0;i<n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    //printf("MATCH %d\n",ans);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
        {
            int a1,a2,a,b,c,d;
            scanf("%d:%d%d%d%d%d",&a1,&a2,&a,&b,&c,&d);
            start[i]=a1*60+a2;
            end[i]=start[i]+ABS(a-c)+ABS(b-d);
            for(int j=0;j<i;j++)
                if(end[j]<start[i])map[j][i]=1;
        }
        printf("%d\n",n-Max_Match());
    }
    //system("pause");
    return 0;
}
