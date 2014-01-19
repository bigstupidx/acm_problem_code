#include <cstdio>
#include <cstring>
int n,map[22][22],flag[22];
int solve(){
    int maxi=-1,fi=1,i=0;
    while(i<n){i++;fi*=2;}
    for(i=1;i<fi;i++){
        int j=0,nn=i,cnt=0;
        memset(flag,0,sizeof(flag));
        while(nn){
            flag[j]=nn%2;
            if(nn%2)cnt++;
            nn>>=1;   j++;
        }
        if(!cnt||cnt==n)continue;
        nn=0;
        for(j=0;j<n;j++){
            if(flag[j]){
                for(int k=0;k<n;k++)
                    if(!flag[k])nn+=map[j][k];
            }
        }
        //printf("%d ",nn);
        if(nn>maxi)maxi=nn;
    }
    return maxi;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                scanf("%d",map[i]+j);
        }
        printf("%d\n",solve());
    }
    return 0;
}
