#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
int n,map[22][22],flag[22];
int solve(){
    int maxi=-1,fi=1,i=0;
    while(i<n){i++;fi*=2;}
    fi/=2;
    for(i=1;i<fi;i++){
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
    //printf("%d %d",5,^5);
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                scanf("%d",map[i]+j);
        }
        printf("%d\n",solve());
    }
    return 0;
}
