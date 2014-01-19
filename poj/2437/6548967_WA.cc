#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
        int s,t;
        bool operator <(const node &a)const{
                return a.s>s;
        }
}nod[10010];
int n,L;
int main()
{
        while(scanf("%d%d",&n,&L)!=EOF){
                for(int i=0;i<n;i++){
                        int u,v;
                        scanf("%d%d",&u,&v);
                        nod[i].s=u;     nod[i].t=v;
                }
                sort(nod,nod+n);
                int ans=0,st=nod[0].s;
                for(int i=0;i<n;i++){
                        if(st<nod[i].s)st=nod[i].s;
                        ans+=(nod[i].t-st)/L;
                        if((nod[i].t-st)%L){
                                ans++;
                                st=L-(nod[i].t-st)%L+nod[i].t;
                        }
                        else
                                st=nod[i].t;
                        //printf("%d %d\n",st,ans);
                }
                printf("%d\n",ans);
        }
        return 0;
}