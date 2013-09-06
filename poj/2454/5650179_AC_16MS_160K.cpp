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
int aa[200];
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
        for(i=0;i<3*k;i++)aa[i]=i;
        while(1)
        {
            j=rand()%(2*k),
            i=rand()%(2*k);
            int temp;
            temp=aa[i];aa[i]=aa[j];aa[j]=temp;
            int sum1=0,sum2=0;
            for(int ii=0;ii<k;ii++)
                sum1+=nod[aa[ii]].w;
            if(sum1<=500*k)continue;
            for(int ii=k;ii<2*k;ii++)
                sum2+=nod[aa[ii]].w;
            if(sum2>500*k)break;
        }
        for(i=0;i<3*k;i++)
            printf("%d\n",nod[aa[i]].i);
    }
    return 0;
}
