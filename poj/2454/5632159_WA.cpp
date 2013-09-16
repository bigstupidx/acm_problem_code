#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
int k,aa[200],sum[3],bb[200],flag[200];
void rand_get()
{
    memset(flag,0,sizeof(flag));
    for(int i=0;i<3*k;i++)
    {
        while(1){
            bb[i]=rand()%(3*k);
            if(!flag[bb[i]]){flag[bb[i]]=1;break;}
        }
//        printf("%d ",bb[i]);
    }
//    puts("");
}
bool check()
{
    memset(sum,0,sizeof(sum));
    for(int i=0;i<k;i++)
        sum[0]+=aa[bb[i]];
    for(int i=k;i<2*k;i++)
        sum[1]+=aa[bb[i]];
    for(int i=2*k;i<3*k;i++)
        sum[2]+=aa[bb[i]];
    if(sum[0]>500*k&&sum[1]>500*k||sum[0]>500*k&&sum[2]>500*k||sum[1]>500*k&&sum[2]>500*k)
        return true;
    return false;
}
int main()
{
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<3*k;i++)
            scanf("%d",aa+i);
        for(int i=0;i<1000000;i++)
        {
            srand((unsigned)time(NULL));
            rand_get();
            if(check())break;
        }
        for(int i=0;i<3*k;i++)
            printf("%d\n",bb[i]+1);
    }
    return 0;
}
