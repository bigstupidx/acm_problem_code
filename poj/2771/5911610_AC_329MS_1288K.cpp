#include<cstdio>
#include<cstring>

struct node{
    int h;
    char mu[120],sp[120];
}n1[502],n2[502];

int n,m,flag[502],y[502],g[502][502];
int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
bool Path(int s)
{
    for(int i=0;i<m;i++)
    {
        if(!flag[i]&&g[s][i])
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
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int nn,h;
        char ss[2],mu[120],sp[120];
        scanf("%d",&nn);
        n=0;    m=0;
        for(int i=0;i<nn;i++){
            scanf("%d%s%s%s",&h,ss,mu,sp);
            if(ss[0]=='M'){
                n1[n].h=h;
                strcpy(n1[n].mu,mu);
                strcpy(n1[n].sp,sp);
                n++;
            }
            else{
                n2[m].h=h;
                strcpy(n2[m].mu,mu);
                strcpy(n2[m].sp,sp);
                m++;
            }
        }
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(strcmp(n1[i].mu,n2[j].mu)==0
            &&strcmp(n1[i].sp,n2[j].sp)!=0&&ABS(n1[i].h-n2[j].h)<=40)
                    g[i][j]=1;
        printf("%d\n",m+n-Max_Match());
    }
    return 0;
}
