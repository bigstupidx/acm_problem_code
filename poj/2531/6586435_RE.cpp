#include <cstdio>
#include <cstring>
int n,map[22][22],flag[22],mark[10000000];
int solve(){
    int maxi=-1,fi=1,i=0;
    while(i<n){i++;fi*=2;}
    --fi;
    for(i=1;i<fi;i++){
        if(mark[i])continue;
        mark[i]=1;mark[~i]=1;
        int j,nn=i;
        for(j=0;j<n;j++)flag[j]=0;
        j=0;
        while(nn){
            flag[j++]=nn%2;
            nn>>=1;
        }
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
        memset(mark,0,sizeof(mark));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                scanf("%d",map[i]+j);
        }
        printf("%d\n",solve());
    }
    return 0;
}
