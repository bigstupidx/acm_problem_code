#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,t;
char name[21][12];
struct node{
    int id;
    int wi;
    bool operator <(const node a)const
    {
        return a.wi>wi;
    }
}nod[21];
int main()
{
    int nca=0;
    while(scanf("%d%d",&n,&t),n||t)
    {
        nca++;
        map<string,int>mp;
        map<string,int>::iterator p;
        for(int i=0;i<n;i++)
        {
            scanf("%s",name[i]);
            mp[name[i]]=i;nod[i].id=i;nod[i].wi=0;
        }
        for(int i=0;i<t;i++)
        {
            int d;
            char name1[12],name2[12];
            scanf("%s%s%d",name1,name2,&d);
            p=mp.find(name1);
            nod[p->second].wi+=d;
            p=mp.find(name2);
            nod[p->second].wi-=d;
        }
        sort(nod,nod+n);
        //for(int i=0;i<n;i++)
        //    printf("%d %d\n",nod[i].id,nod[i].wi);
        printf("Case #%d\n",nca);
        int u=nod[0].id;
        for(int i=1;i<n;i++)
        {
            if(nod[i].wi<0)
            {
                int v=nod[i].id;
                printf("%s %s %d\n",name[v],name[u],-nod[i].wi);
                nod[0].wi+=nod[i].wi;
                nod[i].wi=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int v=nod[i].id;
            if(nod[i].wi>0)
                printf("%s %s %d\n",name[u],name[v],nod[i].wi);
        }
        puts("");
    }
    return 0;
}
