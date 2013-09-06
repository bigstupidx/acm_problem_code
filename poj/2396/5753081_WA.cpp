#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;

int c1[222][222],l[222][222],c[300][300],pre[300],f[300][300];
int row,col,X,Y;
int Max_Flow()
{
    int i,flow=0,xflow=0;
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    c[row+col+2][row+col+1]=inf;
    for(i=1;i<=row;i++)
    {
        c[0][i]+=l[row+col+1][i];
        c[row+col+1][row+col+3]+=l[row+col+1][i];
        xflow+=l[row+col+1][i];
    }
    for(i=row;i<=row+col;i++)
    {
        c[0][row+col+2]+=l[i][row+col+2];
        c[i][row+col+3]+=l[i][row+col+2];
        xflow+=l[i][row+col+2];
    }
    for(i=1;i<=row;i++)
        for(int j=row+1;j<=row+col;j++)
        {
            c[0][j]+=l[i][j];
            c[i][row+col+3]+=l[i][j];
            c[i][j]=c1[i][j]-l[i][j];
            xflow+=l[i][j];
        }
    int s=0,t=col+row+3;
    while(1)
    {
        int mini=inf;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(0);
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=1;j<=t;j++)
            {
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1){
            //printf("%d \n",flow);
            return flow==xflow;
        }
        for(i=t;i!=s;i=pre[i])
            if(c[pre[i]][i]-f[pre[i]][i]<mini)mini=c[pre[i]][i]-f[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
          //  printf("%d ",i);
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
        }
        //printf("\nmini: %d \n",mini);
        flow+=mini;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,qq,tem,flag=0;
        memset(l,0,sizeof(l));
        memset(c1,0,sizeof(c1));
        X=0;    Y=0;
        scanf("%d%d",&row,&col);
        for(i=1;i<=row;i++){
            scanf("%d",&tem);
            c1[row+col+1][i]=tem;
            l[row+col+1][i]=tem;
            X+=tem;
        }
        for(i=1;i<=col;i++){
            scanf("%d",&tem);
            c1[row+i][row+col+2]=tem;
            l[row+i][row+col+2]=tem;
            for(int j=1;j<=row;j++)c1[j][i+row]=tem;
            Y+=tem;
        }

        if(X!=Y)flag=1;
        else c1[row+col+1][row+col+2]=inf;
        int u,v,va;
        char ch[4];
        scanf("%d",&qq);
        while(qq--){
            scanf("%d%d%s%d",&u,&v,ch,&va);
            if(flag)continue;
            if(u==0&&v==0)
            {
                for(int j=1;j<=row;j++)
                    for(int k=row+1;k<=row+col;k++)
                        if(l[j][k]<=va&&c1[j][k]>=va)
                        {
                            if(ch[0]=='=')
                                l[j][k]=c1[j][k]=va;
                            else if(ch[0]=='>'){
                                if(va+1<=c1[j][k])l[j][k]=va+1;
                                else flag=1;
                            }
                            else{
                                if(va-1>=l[j][k])c1[j][k]=va-1;
                                else flag=1;
                            }
                        }
                        else flag=1;
            }
            else if(u==0)
            {
                for(int j=1;j<=row;j++)
                    if(l[j][row+v]<=va&&va<=c1[j][row+v])
                    {
                        if(ch[0]=='=')c1[j][row+v]=l[j][row+v]=va;
                        else if(ch[0]=='>'){
                            if(va+1<=c1[j][row+v])l[j][row+v]=va+1;
                            else flag=1;
                        }
                        else{
                            if(va-1>=l[j][row+v])c1[j][row+v]=va-1;
                            else flag=1;
                        }
                    }
                    else flag=1;
            }
            else if(v==0)
            {
                for(int j=row;j<=row+col;j++)
                    if(c1[u][j]>=va&&l[u][j]<=va)
                    {
                        if(ch[0]=='=')c1[u][j]=l[u][j]=va;
                        else if(ch[0]=='>'){
                            if(va+1<=c1[u][j])l[u][j]=va+1;
                            else flag=1;
                        }
                        else{
                            if(va-1>=l[u][j])c1[u][j]=va-1;
                            else flag=1;
                        }
                    }
                    else flag=1;
            }
            else {
                if(l[u][row+v]<=va&&c1[u][row+v]>=va)
                {
                    if(ch[0]=='=')l[u][row+v]=c1[u][row+v]=va;
                    else if(ch[0]=='>'){
                        if(va+1<=c1[u][row+v])l[u][row+v]=va+1;
                        else flag=1;
                    }
                    else {
                        if(va-1>=l[u][row+v])c1[u][row+v]=va-1;
                        else flag=1;
                    }
                }
                else flag=1;
            }
        }
        if(flag)puts("IMPOSSIBLE");
        else{
            if(!Max_Flow())puts("IMPOSSIBLE");
            else{
                for(i=1;i<=row;i++){
                    for(int j=row+1;j<=row+col;j++)
                        printf("%d ",f[i][j]+l[i][j]);
                    puts("");
                }
            }
        }
        if(t!=0)puts("");
    }
    return 0;
}
