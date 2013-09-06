#include <cstdio>
#include <cstring>

int n,m,y[300];
bool flag[300],map[300][300];
__int64 iniA[300],iniB[300],tim[300][300],speA[300],speB[300];
__int64 tt[300][300],inf;
void Build_G(__int64 mid)
{
    memset(map,0,sizeof(map));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(tt[i][j]<=mid)map[i][j]=1;
}
bool path(int s)
{
    for(int i=1;i<=m;i++)
    {
        if(!flag[i]&&map[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||path(y[i]))
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
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    return ans;
}
int main()
{
    inf=1LL<<60;
    //printf("%I64d\n",inf);
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=1;i<=n;i++){
            scanf("%I64d%I64d",iniA+i,speA+i);
        }
        for(int i=1;i<=m;i++){
            scanf("%I64d%I64d",iniB+i,speB+i);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%I64d",&tim[i][j]);
        if(n<m){
            puts("IMPOSSIBLE");
            continue;
        }
        __int64 maxi=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(speA[i]<=speB[j]&&iniA[i]<speB[j]*tim[i][j]+iniB[j])
                    tt[i][j]=inf;
                else if(iniA[i]>=speB[j]*tim[i][j]+iniB[j])
                    tt[i][j]=0;
                else{
                    __int64 x=(speB[j]*tim[i][j]+iniB[j]-iniA[i])
                        /(speA[i]-speB[j]);
                    if(iniA[i]+x*speA[i]>=iniB[j]+speB[j]*(tim[i][j]+x))
                        tt[i][j]=x;
                    else tt[i][j]=x+1;
                    tt[i][j]+=tim[i][j];
                    if(maxi<tt[i][j])maxi=tt[i][j];
                }
            }
        }/*
        for(int i=1;i<=n;i++)
            printf("%I64d ",iniA[i]);
        puts("");
        
        for(int i=1;i<=n;i++)
            printf("%I64d ",speA[i]);
        puts("");
        
        for(int i=1;i<=m;i++)
            printf("%I64d ",iniB[i]);
        puts("");
        
        for(int i=1;i<=m;i++)
            printf("%I64d ",speB[i]);
        puts("");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%I64d ",tt[i][j]);
            puts("");
        }*/
        __int64 l=0,r=maxi,mid;
        while(l<=r){
            mid=(l+r)/2;
            //printf("%I64d mid",mid);
            Build_G(mid);
            if(Max_Match()==m)
                r=mid-1;
            else
                l=mid+1;
        }
        if(l>maxi)puts("IMPOSSIBLE");
        else printf("%d\n",l);
    }
    return 0;
}
