#include<cstdio>
#include<cstring>
int sumr[100],sumc[100];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int tem;
        memset(sumr,0,sizeof(sumr));
        memset(sumc,0,sizeof(sumc));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&tem);
                sumr[i]+=tem;
                sumc[j]+=tem;
            }
        }
        int i,j,cnt=0,rnt=0;
        for(int k=1;k<=n;k++)
        {
            if(sumr[k]%2==1)
            {
                i=k;cnt++;
            }
            if(sumc[k]%2==1)
            {
                j=k;rnt++;
            }
        }
        if(cnt==0&&rnt==0)puts("OK");
        else if(cnt==1&&rnt==1)
            printf("Change bit (%d,%d)\n",i,j);
        else puts("Corrupt");
    }
    return 0;
}
