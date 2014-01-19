#include<algorithm>
#include<iostream>
#define N 1000010
using namespace std;
int q[N],bb[N];
int flag[65536];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(flag,0,sizeof(flag));
        int m=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&bb[i]);
            if(!flag[bb[i]%65536])
            {
                m++;
                flag[bb[i]%65536]=1;
            }
        }
        int front=0,tail=0,min=N,count=1;
        memset(flag,0,sizeof(flag));
        q[tail++]=0;
        flag[bb[0]%65536]++;
        for(int i=1;i<n;i++)
        {
            q[tail++]=i;
            if(!flag[bb[i]%65536])
            {
                count++;
                flag[bb[i]%65536]++;
            }
            else
            {
                flag[bb[i]%65536]++;
                while(flag[bb[q[front]]%65536]>1)
                {
                    flag[bb[q[front]]%65536]--;
                    front++;
                }
            }
            if(count==m && tail-front<min)
                min=tail-front;
            if(min==m)break;
        }
        if(count==1)min=1;
        printf("%d\n",min);
    }
    return 0;
}
