#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
struct node{
    int i,w;
    bool operator<(const node a)const
    {
        return a.w<w;
    }
}nod[200];
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        int i,j;
        for(i=0;i<3*k;i++)
        {
            scanf("%d",&nod[i].w);
            nod[i].i=i+1;
        }
        sort(nod,nod+3*k);
        srand((unsigned)time(0));
        while(1)
        {
            j=rand()%(2*k),
            i=rand()%(2*k);
            int temp;
            temp=nod[i].w;nod[i].w=nod[j].w;nod[j].w=temp;
            int sum1=0,sum2=0;
            for(int ii=0;ii<k;ii++)
                sum1+=nod[ii].w;
            if(sum1<=500*k)continue;
            for(int ii=k;ii<2*k;ii++)
                sum2+=nod[ii].w;
            if(sum2>500*k)break;
        }
        for(i=0;i<3*k;i++)
            printf("%d\n",nod[i].i);
    }
    return 0;
}
