#include<cstdio>
#include<algorithm>
int aa[1010];
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        int i,total,n,sum=0;
        scanf("%d%d",&total,&n);
        for(int i=0;i<n;i++)
            scanf("%d",aa+i);
        std::sort(aa,aa+n);
        for(i=n-1;i>=0;i--)
        {
            sum+=aa[i];
            if(sum>=total)
                break;
        }
        printf("Scenario #%d:\n",ii);
        if(i<0)printf("impossible\n\n");
        else printf("%d\n\n",n-i);
    }
    return 0;
}
