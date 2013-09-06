#include<cstdio>
#include<cstring>
int ma[65][65],mod,n,temp[65][65],c[65][65];
void fi(int k)
{
    if(k==1)
    {
        for(int i=0;i<2*n;i++)
            for(int j=0;j<2*n;j++)
                c[i][j]=ma[i][j]%mod;
        return ;
    }
    fi(k/2);
    memset(temp,0,sizeof(temp));
    for(int i=0;i<2*n;i++)
        for(int j=0;j<2*n;j++)
            for(int k=0;k<2*n;k++)
                temp[i][j]=(temp[i][j]+c[i][k]*c[k][j])%mod;
    if(k%2)
    {
        memset(c,0,sizeof(c));
        for(int i=0;i<2*n;i++)
            for(int j=0;j<2*n;j++)
                for(int k=0;k<2*n;k++)
                    c[i][j]=(c[i][j]+temp[i][k]*ma[k][j])%mod;
    }
    else{
        for(int i=0;i<2*n;i++)
            for(int j=0;j<2*n;j++)
                c[i][j]=temp[i][j];
    }
    return ;
}
int main()
{
    int k;
    scanf("%d%d%d",&n,&k,&mod);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&ma[i][j]);
        for(int j=n;j<2*n;j++)
            if(j-n==i)ma[i][j]=1;
    }
    for(int i=n;i<2*n;i++)
        for(int j=0;j<2*n;j++)
            if(j==i)ma[i][j]=1;
    fi(k+1);
    for(int i=0;i<n;i++){
       for(int j=n;j<2*n;j++)
           if(j-n==i)printf("%d ",c[i][j]-1);
           else printf("%d ",c[i][j]);
       printf("\n");
    }
    return 0;
}
