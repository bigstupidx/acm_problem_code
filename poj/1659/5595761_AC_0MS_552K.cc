#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
struct node{
    int i;
    int d;
    bool operator<(const node a)const
    {
        return a.d<d;
    }
}nod[20];
int n,map[12][12];
void solve()
{
    memset(map,0,sizeof(map));
    int flag=0;

    while(1)
    {
        sort(nod,nod+n);
        int temp=nod[0].d,i=1;
        if(temp==0)break;
        nod[0].d=0;
        while(temp)
        {
            temp--;
            nod[i].d--;
            if(nod[i].d<0){flag=1;break;}
            map[nod[0].i][nod[i].i]=1;
            map[nod[i].i][nod[0].i]=1;
            i++;
        }
        if(flag)break;
    }
    if(flag){puts("NO");return ;}
    puts("YES");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&nod[i].d);
            nod[i].i=i;
        }
        solve();
        if(t!=0)puts("");
    }
    return 0;
}
