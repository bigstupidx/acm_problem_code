#include <cstdio>
#include <cstring>
#define MAXN 1010
int n,aa[MAXN],bb[MAXN];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",aa+i);
        bb[0]=1;
        for(int i=1;i<n;i++)
        {
            bb[i]=1;
            for(int j=0;j<i;j++)
                if(aa[j]<aa[i]&&bb[i]<bb[j]+1)
                    bb[i]=bb[j]+1;
        }
        int maxi=-1;
        for(int i=0;i<n;i++)
            if(maxi<bb[i])maxi=bb[i];
        //for(int i=0;i<n;i++)
        //    printf("%d ",bb[i]);
        //puts("");
        printf("%d\n",maxi);
    }
    return 0;
}
