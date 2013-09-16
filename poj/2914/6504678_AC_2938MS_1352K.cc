#include <cstdio>
#include <cstring>
bool A[502];
const int inf = 1000000000;
int m,n,map[502][502],id[502],wi[502];
int mini_cut(){
    int ans=inf;
    for(int i=0;i<n;i++)id[i]=i;
    while(n>1){
        int mini=1;
        A[id[0]]=true;
        for(int i=1;i<n;i++){
            A[id[i]]=false;
            wi[i]=map[id[0]][id[i]];
            if(wi[i]>wi[mini])
                mini=i;
        }
        int t=n,pre;
        while(t--){
            A[id[mini]]=true;
            if(t==1){
                if(ans>wi[mini])
                    ans=wi[mini];
                for(int i=0;i<n;i++){
                    map[id[pre]][id[i]]+=map[id[mini]][id[i]];
                    map[id[i]][id[pre]]=map[id[pre]][id[i]];
                }
                id[mini]=id[--n];
                break;
            }
            pre=mini;   mini=-1;
            for(int i=0;i<n;i++){
                if(A[id[i]])continue;
                wi[i]+=map[id[pre]][id[i]];
                if(mini==-1||wi[i]>wi[mini])
                    mini=i;
            }
        }
        
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++){
            int u,v,va;
            scanf("%d%d%d",&u,&v,&va);
            map[u][v]+=va;
            map[v][u]+=va;
        }
        printf("%d\n",mini_cut());
    }
    return 0;
}
