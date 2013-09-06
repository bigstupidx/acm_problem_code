#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int id;
    int d;
    bool operator <(const node &a)const{
        return a.d<d;
    }
}nod[12];
int n,map[12][12];
int solve()
{
    memset(map,0,sizeof(map));
    for(int i=0;i<n;i++){
        sort(nod+i,nod+n);
        int u=nod[i].id;
        int m=nod[i].d;
        for(int j=i+1;j<n&&m;j++){
            if(--nod[j].d<0)return -1;
            m--;
            int v=nod[j].id;
            map[u][v]=map[v][u]=1;
        }
    }
    return 1;
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            nod[i].id=i;
            scanf("%d",&nod[i].d);
        }
        int ans=solve();
        if(ans==-1)puts("NO");
        else{
            puts("YES");
            for(int i=0;i<n;i++){
                printf("%d",map[i][0]);
                for(int j=1;j<n;j++)
                    printf(" %d",map[i][j]);
                puts("");
            }
        }
        if(nca!=0)puts("");
    }
    system("pause");
    return 0;
}
