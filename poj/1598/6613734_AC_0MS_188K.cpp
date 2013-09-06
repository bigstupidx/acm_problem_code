#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    char str[80];
    int cnt;
    bool operator <(const node &a)const{
        return a.cnt<cnt;
    }
}nod[30];
int n,m,flag[80];
int main()
{
    int nca=1;
    while(scanf("%d%d",&n,&m)!=EOF){
        char str[80],tem[80];
        map<string,int>mp;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            mp[str]=1;
        }
        getchar();
        for(int i=0;i<m;i++){
            gets(nod[i].str);
            strcpy(tem,nod[i].str);
            int k=0,len=strlen(tem);
            memset(flag,0,sizeof(flag));
            for(int j=0;j<len;j++){
                if(tem[j]<='Z'&&tem[j]>='A'){
                    flag[j]=1;
                    tem[j]+='a'-'A';
                }
                else if(tem[j]>='a'&&tem[j]<='z')
                    flag[j]=1;
            }
            nod[i].cnt=0;
            for(int j=0;j<len;j++){
                if(!flag[j]){
                    for(int jj=k;jj<j;jj++)
                        str[jj-k]=tem[jj];
                    str[j-k]=0;
                    if(mp.find(str)!=mp.end())nod[i].cnt++;
                    while(j<len&&!flag[j])j++;
                    k=j;
                }
            }
            //printf("%d\n",nod[i].cnt);
        }
        sort(nod,nod+m);
        printf("Excuse Set #%d\n",nca++);
        puts(nod[0].str);
        for(int i=1;i<m;i++){
            if(nod[i].cnt==nod[i-1].cnt)
                puts(nod[i].str);
            else
                break;
        }
        puts("");
    }
    return 0;
}
