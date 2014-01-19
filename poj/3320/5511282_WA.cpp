#include<algorithm>
#include<iostream>
#define N 1000010
using namespace std;
int q[N],flag[N];
struct nod{
    int i;
    int va;
}bb[N];
bool cmp1(nod a,nod b)
{
    return a.va<b.va;
}
bool cmp2(nod a,nod b)
{
    return a.i<b.i;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&bb[i].va);
            bb[i].i=i;
        }
        sort(bb,bb+n,cmp1);
        int id=0,va=bb[0].va;
        bb[0].va=id;
        for(int i=1;i<n;i++)
        {
            if(bb[i].va!=va)
            {
                va=bb[i].va;
                bb[i].va=++id;
            }
            else bb[i].va=id;
        }
        sort(bb,bb+n,cmp2);
        int front=0,tail=0,min=N,count=1;
        memset(flag,0,sizeof(flag));
        q[tail++]=bb[0].va;
        flag[bb[0].va]=1;
        for(int i=1;i<n;i++)
        {
            q[tail++]=i;
            if(!flag[bb[i].va])
            {
                count++;
                flag[bb[i].va]++;
            }
            else
            {
                flag[bb[i].va]++;
                while(flag[bb[q[front]].va]>1)
                {
                    flag[bb[q[front]].va]--;
                    front++;
                }
            }
            if(count==id+1&&tail-front<min)
                min=tail-front;
            if(min==id+1)break;
        }
        if(count==1)min=1;
        printf("%d\n",min);
    }
    return 0;
}
