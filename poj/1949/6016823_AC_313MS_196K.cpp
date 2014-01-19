#include <cstdio>
int tim[10010];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int maxi=-1;
        for(int i=1;i<=n;i++)
        {
            int m,pre,temp=0;
            scanf("%d%d",&tim[i],&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&pre);
                if(tim[pre]>temp)temp=tim[pre];
            }
            tim[i]=temp+tim[i];
            if(maxi<tim[i])maxi=tim[i];
        }
        //for(int i=1;i<=n;i++)
        //    printf("%d ",tim[i]);
        //puts("");
        printf("%d\n",maxi);
    }
    return 0;
}
