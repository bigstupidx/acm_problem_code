#include<stdio.h>
__int64 c[34][34];
__int64 dit[34];
void pre_done()
{
    for(int i=0;i<34;i++)
        c[i][0]=c[i][i]=1;
    for(int i=2;i<34;i++)
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    dit[1]=1;dit[2]=2;
    for(int i=3;i<34;i++)
    {
        dit[i]=dit[i-1];
        for(int j=0;j<i/2;j++)
            dit[i]+=c[i-1][j];
    }
    return ;
}

__int64 solve(__int64 n)
{
    int aa[34],top=0;
    while(n)
    {
        aa[top++]=n%2;
        n/=2;
    }
    __int64 ans=dit[top];
    int ones=1,i=top-2;
    do
    {
        if(ones > top/2)break;
        if(aa[i] == 0)
        {
            for(int j=0;j<=top/2-ones-1;j++)
                ans-=c[i][j];
        }
        else
            ones++; 
    }while(--i != -1);
    return ans;
}
int judge(__int64 x)
{
    int aa[34],top;
    int zeros=0,ones=0;
    while(x)
    {
        if(x%2)ones++;
        else zeros++;
        x/=2;
    }
    if(zeros<ones)return 0;
    return 1;
}
int main()
{
    __int64 st,en;
    pre_done();
    while(scanf("%I64d%I64d",&st,&en)!=EOF)
    {
        __int64 x,y,ans;
        x=solve(st);
        y=solve(en);
        if(!judge(x))ans=y-x;
        else ans=y-x+1;
        printf("%I64d\n",ans);
    }
    return 0;
}

