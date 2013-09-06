#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
struct node{
    int i;
    int cost;
    bool operator<(const node a)const
    {
        return a.cost>cost;
    }
}nod[200];
int k,sum[3];

bool check()
{
    sum[1]=0;sum[2]=0;
    for(int i=k;i<2*k;i++)
        sum[1]+=nod[i].cost;
    for(int i=2*k;i<3*k;i++)
        sum[2]+=nod[i].cost;
    if(sum[1]>500*k&&sum[2]>500*k)
    {
        //printf("%d %d %d\n",sum[0],sum[1],sum[2]);
        return true;
    }
    return false;
}
int main()
{
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<3*k;i++){
            scanf("%d",&nod[i].cost);
            nod[i].i=i+1;
        }
        sort(nod,nod+3*k);
        while(1)
        {
            srand((unsigned)time(NULL));
            random_shuffle(nod+k,nod+3*k);
            if(check())break;
        }
        for(int i=0;i<3*k;i++)
            printf("%d\n",nod[i].i);
    }
    return 0;
}
