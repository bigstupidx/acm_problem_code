#include <cstdio>
#include <cstring>
int n,arr[30010],oneb[30010],twob[30010],onea[30010],twoa[30010];
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        memset(onea,0,sizeof(onea));
        memset(oneb,0,sizeof(oneb));
        memset(twoa,0,sizeof(twoa));
        memset(twob,0,sizeof(twob));
        for(int i=1;i<=n;i++){
            oneb[i]=oneb[i-1];
            twob[i]=twob[i-1];
            if(arr[i]==1)
                oneb[i]++;
            else
                twob[i]++;
        }
        for(int i=n;i>0;i--){
            onea[i]=onea[i+1];
            twoa[i]=twoa[i+1];
            if(arr[i]==1)
                onea[i]++;
            else
                twoa[i]++;
        }
        int mini=onea[1]>twoa[1]?twoa[1]:onea[1];
        for(int i=1;i<=n;i++){
            int tem=twob[i-1]+onea[i];
            if(tem<mini)
                mini=tem;
        }
        printf("%d\n",mini);
    }
    return 0;
}
