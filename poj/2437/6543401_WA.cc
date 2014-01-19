#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int u,v;
    bool operator <(const node &a)const{
        return a.u>u;
    }
}nod[10002];
int n,L;
int main()
{
    while(scanf("%d%d",&n,&L)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&nod[i].u,&nod[i].v);
        }
        sort(nod,nod+n);
        //printf("%d %d\n",nod[0].u,nod[0].v);
        int ans=0,st=nod[0].u;
        for(int i=0;i<n;i++){
            if(st<nod[i].u)st=nod[i].u;
            ans+=(nod[i].v-st)/L;
            if((nod[i].v-st)%L){
                ans++;
                st=nod[i].v+(L-(nod[i].v-st)%L);
            }
            else{
                st=nod[i].v;
            }
           //printf("%d ",st);
        }
        printf("%d\n",ans);
    }
    return 0;
}
