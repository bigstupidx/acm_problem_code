#include<cstdio>
#include<cmath>
#include<cstring>
struct node{
    int x,y;
}nod[202];
double map[102][102];
double Lx[102],Ly[102];
int n,xflag[102],yflag[102],mx[102],my[102];
double Distance(int i,int j)
{
    double ans;
    ans=(nod[i].x-nod[j].x)*(nod[i].x-nod[j].x)
        +(nod[i].y-nod[j].y)*(nod[i].y-nod[j].y);
    return sqrt(ans);
}
bool Path(int s)
{
    xflag[s]=1;
    for(int i=0;i<n;i++)
    {
        if(!yflag[i]&&Lx[s]+Ly[i]==map[s][i])
        {
            yflag[i]=1;
            if(my[i]==-1||Path(my[i]))
            {
                mx[s]=i;
                my[i]=s;
                return true;
            }
        }
    }
    return false;
}
void KM_Match()
{
    memset(my,-1,sizeof(my));
    for(int i=0;i<n;i++){
        while(1){
            double mini=100000000;
            memset(xflag,0,sizeof(xflag));
            memset(yflag,0,sizeof(yflag));
            if(Path(i))break;
            for(int j=0;j<n;j++)
                if(xflag[j]){
                    for(int k=0;k<n;k++)
                        if(!yflag[k]&&mini>Lx[j]+Ly[k]-map[j][k])
                            mini=Lx[j]+Ly[k]-map[j][k];
            }
            for(int j=0;j<n;j++)
                if(xflag[j])
                    Lx[j]-=mini;
            for(int j=0;j<n;j++)
                if(yflag[j])
                    Ly[j]+=mini;
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<2*n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        for(int i=0;i<n;i++){
            Lx[i]=-1;
            for(int j=0;j<n;j++){
                map[i][j]=100000000-Distance(i,j+n);
                if(map[i][j]>Lx[i])Lx[i]=map[i][j];
            }
            Ly[i]=0;
        }
        KM_Match();
        for(int i=0;i<n;i++)
            printf("%d\n",mx[i]+1);
    }
    return 0;
}
