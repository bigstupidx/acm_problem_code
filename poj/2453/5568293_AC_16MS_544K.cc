#include<cstdio>
#include<cstring>
#include<algorithm>

int aa[30],bb[30];
bool cmp(int a ,int b)
{
    return a>b;
}
void pre_done()
{
    bb[0]=1;
    for(int i=1;i<30;i++)
        bb[i]=bb[i-1]*2;
}
int main()
{
    int n;
    pre_done();
    while(scanf("%d",&n),n)
    {
        int top=0,j;
        memset(aa,0,sizeof(aa));
        while(n)
        {
            aa[top++]=n%2;
            n/=2;
        }
        for(j=1;j<=top;j++)
            if(aa[j]==0&&aa[j-1]==1)break;
        if(j==top)top++;
        aa[j]=1;aa[j-1]=0;
        std::sort(aa,aa+j,cmp);
        n=0;j=0;
        while(j<top)
            n+=aa[j]*bb[j++];
        printf("%d\n",n);
    }
    return 0;
}
