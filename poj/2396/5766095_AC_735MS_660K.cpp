#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;
int n,l[250][250],c[250][250],X,Y,pre[250];

int Max(int x,int y)
{
    if(x>y)return x;
    return y;
}
int Min(int x,int y)
{
    if(x>y)return y;
    return x;
}
bool Adjust(char ch,int i,int j,int va)
{
    if(ch=='='){
        if(l[i][j]>va||va>c[i][j])return false;
        l[i][j]=c[i][j]=va; return true;
    }
    if(ch=='>'){
        if(c[i][j]>va)
            l[i][j]=Max(l[i][j],va+1);
        else return false;
    }
    else{
        if(l[i][j]<va)
            c[i][j]=Min(c[i][j],va-1);
        else return false;
    }
    return true;
}
void Build_G()
{
    Y=0;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n+1;j++)
            if(c[i][j]>=l[i][j]&&l[i][j]>0)
            {
                c[0][j]+=l[i][j];
                c[i][n+2]+=l[i][j];
                c[i][j]-=l[i][j];
                Y+=l[i][j];
            }
}
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf,i;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=1;j<=t;j++)
            {
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow==Y;
        for(i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int row,col,i,tem,flag=0;
        memset(c,0,sizeof(c));
        memset(l,0,sizeof(l));
        scanf("%d%d",&row,&col);
        n=row+col+1;  X=0;    Y=0;
        for(i=1;i<=row;i++){
            scanf("%d",&tem);
            c[n][i]=l[n][i]=tem;
            X+=tem;
        }
        for(i=row+1;i<=row+col;i++)
        {
            scanf("%d",&tem);
            c[i][n+1]=l[i][n+1]=tem;
            for(int j=1;j<=row;j++)c[j][i]=tem;
            Y+=tem;
        }
        if(X!=Y)flag=1;
        int qq,u,v,va;
        char ch[4];
        scanf("%d",&qq);
        while(qq--)
        {
            scanf("%d%d%s%d",&u,&v,ch,&va);
            if(flag)continue;
            if(u==0&&v==0){
                for(int j=1;j<=row;j++)
                    for(int k=row+1;k<=row+col;k++)
                        if(!Adjust(ch[0],j,k,va))   flag=1;
            }
            else if(u==0&&v){
                for(int j=1;j<=row;j++)
                    if(!Adjust(ch[0],j,v+row,va))   flag=1;
            }
            else if(v==0&&u){
                for(int j=row+1;j<=row+col;j++)
                    if(!Adjust(ch[0],u,j,va))   flag=1;
            }
            else{
                if(!Adjust(ch[0],u,v+row,va))   flag=1;
            }
        }
       
        if(flag)puts("IMPOSSIBLE");
        else{
            c[n+1][n]=inf;
            Build_G();
            if(!Max_Flow(0,n+2))puts("IMPOSSIBLE");
            else{
                for(i=1;i<=row;i++){
                    for(int j=row+1;j<=row+col;j++)
                        printf("%d ",l[i][j]+c[j][i]);
                    puts("");
                }
            }
        }
        if(t!=0)puts("");
    }
    return 0;
}
