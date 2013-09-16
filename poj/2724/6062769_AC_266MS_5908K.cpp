#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
int mm[2002][12];
int gra[1200][1200],my[1200],n,m,flag[2010],id[2010];
int aa[12]={1,2,4,8,16,32,64,128,256,512,1024};
bool OK(int i,int j)
{
    int cnt=0;
    if(flag[i]==flag[j])return false;
    for(int k=0;k<n;k++){
        if(mm[i][k]!=mm[j][k]){
            cnt++;
        }
    }
    if(cnt==1)return true;
    return false;
}
bool path(int s,int Y)
{
    for(int i=0;i<Y;i++){
        if(!flag[i]&&gra[s][i]){
            flag[i]=1;
            if(my[i]==-1||path(my[i],Y)){
                my[i]=s;
                return true;
            }
        }
    }
    return false;
}
int max_match(int X,int Y)
{
    int ans=0;
    memset(my,-1,sizeof(my));
    for(int i=0;i<X;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i,Y))ans++;
    }
    return ans;
}
int main()
{
    char str[12];
    while(scanf("%d%d",&n,&m),m||n){
        int tem,k=-1;
        map<int,int>mp;
        for(int i=0;i<m;i++){
            int x=-1;k++;
            scanf("%s",str);
            tem=0;
            for(int j=0;j<n;j++){
                if(str[j]=='*'){
                    x=j;continue;
                }
                mm[k][j]=str[j]-'0';
                tem+=aa[n-j-1]*(str[j]-'0');
            }
            if(x!=-1){
                if(mp.find(tem)!=mp.end()){
                    tem+=aa[n-x-1];
                    if(mp.find(tem)!=mp.end())k--;
                    else {
                        mp[tem]=1;mm[k][x]=1;
                    }
                }
                else{
                    mp[tem]=1;
                    tem+=aa[n-x-1];
                    if(mp.find(tem)==mp.end()){
                        k++;    mp[tem]=1;
                        for(int j=0;j<n;j++)
                            mm[k][j]=mm[k-1][j];
                        mm[k][x]=1;mm[k-1][x]=0;
                    }
                    else mm[k][x]=0;
                }
            }
            else{
                if(mp.find(tem)!=mp.end())k--;
                else mp[tem]=1;
            }
        }
        /*
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++)
                printf("%d ",mm[i][j]);
            puts("");
        }
        */
        int n1=0,n2=0;
        for(int i=0;i<=k;i++){
            int cnt=0;
            for(int j=0;j<n;j++)
                if(mm[i][j])cnt++;
            if(cnt%2){
                flag[i]=1;id[i]=n1++;
            }
            else {
                flag[i]=2;id[i]=n2++;
            }
        }
        /*
        for(int i=0;i<=k;i++)
            printf("%d ",flag[i]);
        puts("");
        for(int i=0;i<=k;i++)
            printf("%d ",id[i]);
        puts("");
        */
        memset(gra,0,sizeof(gra));
        for(int i=0;i<=k;i++){
            for(int j=i+1;j<=k;j++){
                if(OK(i,j)){
                    if(flag[i]==1)gra[id[i]][id[j]]=1;
                    else gra[id[j]][id[i]]=1;
                }
            }
        }
        /*
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++)
                printf("%d ",map[i][j]);
            puts("");
        }
        */
        printf("%d\n",n1+n2-max_match(n1,n2));
    }
    return 0;
}
