#include<cstdio>
#include<cstring>
#include<algorithm>

int aa[20],bb[20]={1,2,4,8,16,32,64,128,256,512,1024,4048};
bool cmp(int a ,int b)
{
    return a>b;
}
int main()
{
    int n;
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
