#include <cstdio>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, m, arr[22][12], flag[22][12];
char name[22][10];
struct node{
    int ii, pro, tim, rank;
    int arr[12];
    bool operator <(const node &a)const{
        if(a.pro==pro&&a.tim==tim)
            return a.ii > ii;
        if(a.pro==pro)
            return a.tim > tim;
        return a.pro < pro;
    }
}nod[22];

int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        map<string,int>mp;
        map<string,int>::iterator p;
        memset(arr,0,sizeof(arr));
        memset(flag,0,sizeof(flag));
        
        scanf("%d",&n);
        
        int len, maxi = -1;
        for(int i=0;i<n;i++){
            scanf("%s",name[i]);
            len=strlen(name[i]);
            if(len>maxi)maxi=len;
            mp[name[i]]=i;
            nod[i].ii=i;
            nod[i].pro=0;
            nod[i].tim=0;
        }
        scanf("%d%d",&k,&m);
        int pro_id, tim, team_id;
        char sta[5], team[10];
        for(int i=0;i<m;i++){
            scanf("%d%d%s%s", &pro_id, &tim, sta, team);
            p=mp.find(team);
            team_id=p->second;
            if(flag[team_id][pro_id])continue;
            if(strcmp(sta, "Yes")==0){
                flag[team_id][pro_id]=1;
                nod[team_id].pro++;
                nod[team_id].tim+=tim+arr[team_id][pro_id];
            }
            else{
                arr[team_id][pro_id]+=20;
            }
        }
        sort(nod,nod+n);
        nod[0].rank = 1;
        int rank = 1;
        for(int i=1;i<n;i++){
            if(nod[i].pro==nod[i-1].pro&&nod[i].tim==nod[i-1].tim){
                nod[i].rank = nod[i-1].rank;
                rank = nod[i].rank;
            }
            else{
                nod[i].rank = i+1;
                rank = i + 1;
            }
        }
        //printf("%d \n", tim_maxi);
        for(int j,i=0;i<n;i++){
            printf("%2d. ", nod[i].rank);
            printf("%s", name[nod[i].ii]);
            len=strlen(name[nod[i].ii]);
            for(j = len; j < 9; j++)
                putchar(' ');
            printf("%d ", nod[i].pro);
            if(nod[i].tim!=0)
                j = (int)(log10(1.0*nod[i].tim))+1;
            else
                j=1;
            for(;j<4;j++)
                putchar(' ');
            printf("%d\n", nod[i].tim);
        }
        puts("");
    }
    return 0;
}
