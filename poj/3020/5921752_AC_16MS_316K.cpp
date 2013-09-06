#include<cstdio>
#include<cstring>
char str[42][12];
bool g[402][402],flag[402];
int n,y[402];
bool path(int s)
{
    for(int i=0;i<n;i++)
    {
        if(!flag[i]&&g[s][i])
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
int maxMatch()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    for(int i=0;i<n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    //for(int i=0;i<n;i++)
    //    if(y[i]!=-1)printf("%d - %d\n",y[i],i);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c,sum=0;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++)
            scanf("%s",str[i]);
        memset(g,0,sizeof(g));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(str[i][j]!='*')continue;
                sum++;
                if((i+j)%2){
                    if(i-1>=0&&str[i-1][j]=='*')
                        g[(i-1)*c+j][i*c+j]=1;
                    if(i+1<r&&str[i+1][j]=='*')
                        g[(i+1)*c+j][i*c+j]=1;
                    if(j-1>=0&&str[i][j-1]=='*')
                        g[i*c+j-1][i*c+j]=1;
                    if(j+1<c&&str[i][j+1]=='*')
                        g[i*c+j+1][i*c+j]=1;
                }
                else{
                    if(i-1>=0&&str[i-1][j]=='*')
                        g[i*c+j][(i-1)*c+j]=1;
                    if(i+1<r&&str[i+1][j]=='*')
                        g[i*c+j][(i+1)*c+j]=1;
                    if(j-1>=0&&str[i][j-1]=='*')
                        g[i*c+j][i*c+j-1]=1;
                    if(j+1<c&&str[i][j+1]=='*')
                        g[i*c+j][i*c+j+1]=1;
                }
            }
        }
        n=r*c;
        printf("%d\n",sum-maxMatch());
    }
    return  0;
}
