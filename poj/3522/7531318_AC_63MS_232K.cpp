#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;

struct Tree{
       int a;
       int b;
       int len;
}node[10000];

bool  Cmp(Tree n1,Tree n2){
      if(n1.len <= n2.len) return true;
      return  false;
}
int   f[110];

int   FindSet(int x){
      if(x!=f[x]) f[x]=FindSet(f[x]);
      return f[x];
}

int   main()
{
      while(scanf("%d%d",&n,&k)!=EOF){
            if(n==0&&k==0) break;
            for(int i=0;i<k;i++){
                scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].len);
            }
            sort(node,node+k, Cmp);
            int i;
            int minn=node[0].len;
            int ans=99999999;
            bool state=false;//判断是否有树
            if(k>=n-1){
               for(i=0;i<=k-n+1;i++){
                   if(i==0||node[i].len>minn){
                      for(int s=1;s<=n;s++){
                         f[s]=s;
                      }
                       int fx=node[i].a;
                       int fy=node[i].b;
                       f[fx]=fy;
                       minn=node[i].len;
                       int  num=1;
                       if(num==n-1){
                            ans=0;
                            state=true;
                            break;
                       }
                       for(int p=i+1;p<k;p++){
                           fx=FindSet(node[p].a);
                           fy=FindSet(node[p].b);
                           if(fx!=fy){
                              f[fx]=fy;
                              num++;
                           }
                           if(num==n-1){
                              int cur=node[p].len-minn;
                              ans=ans<cur?ans:cur;
                              state=true;
                              break;
                           }
                      }
                      if(!state) break;
                   }

              }
            }
            if(state) printf("%d\n",ans);
               else printf("-1\n");
      }
      //system("pause");
}