#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 600
#define inf 1000000000

using namespace std;
int map[N][N],w[N],v[N],n;
bool A[N];
int Get_Num()
{
    char ch;
    while (ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while ((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int Min_Cut()
{
    int mini=inf;
    for(int i=0;i<n;i++)
        v[i]=i;
    while(n>1)
    {
        int maxj=1;

        A[v[0]]=true;
        for(int i=1;i<n;i++)
        {
            A[v[i]]=false;
            w[i]=map[v[0]][v[i]];
            if(w[i]>w[maxj])
                maxj=i;
        }
        int t=n,pre=0;
        while(--t)
        {
            A[v[maxj]]=true;
            if(t==1){
                mini=min(mini,w[maxj]);
                for(int i=0;i<n;i++)
                    map[v[i]][v[pre]]=(map[v[pre]][v[i]]+=map[v[maxj]][v[i]]);
                v[maxj]=v[--n];
                break;
            }
            pre=maxj;
            maxj=-1;
            for(int i=0;i<n;i++)
            {
                if(A[v[i]])continue;
                w[i]+=map[v[pre]][v[i]];
                if(maxj<0||w[i]>w[maxj])
                    maxj=i;
            }
        }
    }
    return mini;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        while(m--)
        {
            int i,j,va;
            i=Get_Num();
            j=Get_Num();
            va=Get_Num();
            map[i][j]+=va;
            map[j][i]+=va;
        }
        printf("%d\n",Min_Cut());
    }
    return 0;
}
