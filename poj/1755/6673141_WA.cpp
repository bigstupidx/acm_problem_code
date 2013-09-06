#include <cstdio>
#include <cstring>
int n,spu[102],spv[102],spw[102],flag[102];
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d%d",spu+i,spv+i,spw+i);
        }
        for(int i=0;i<n;i++){
            int cnt=0;
            memset(flag,0,sizeof(flag));
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(spu[j]>=spu[i])flag[j]=1;
            }
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(!flag[j])continue;
                if(spv[j]<spv[i])flag[j]=0;
            }
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(!flag[j])continue;
                if(spw[j]<spw[i])flag[j]=0;
                else cnt++;
            }
            if(cnt==0)puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
