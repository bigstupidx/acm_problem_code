#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN = 4000;

vector<int> mapA[MAXN],mapB[MAXN]; //mapBÊÇmapAµÄ·´ÏòÍ¼
struct{int x,y;}dr[MAXN];   //¼ÇÂ¼doorÉÏµÄÁ½°ÑËø
int opp[MAXN]; //opp[i]±íÊ¾Óëi³åÍ»µÄÔªËØ¡£¼´Í¬×éµÄÔ¿³×¡£

bool vist[MAXN];    //dfsÓÃ
int path[MAXN];     //dfsÓÃ£¬´æÂ·¾¶
int belong[MAXN];   //dfsÓÃ£¬´æ¸÷µãËùÊôµÄSCCºÅ

int n,m,cnt,c_id;   //cntÓÃÒÔÂ·¾¶¼ÆÊý¡¢c_idÎªÁ¬Í¨·ÖÁ¿µÄ±êºÅ


void dfsA(int v){ //Õë¶Ô2N¸öÔ¿³×½áµã£¬½øÐÐDFS¡£±éÀúËùÓÐÁªÍ¨·ÖÁ¿
    vist[v]=1;
    for(int i=0;i<mapA[v].size();i++)
        if(vist[mapA[v][i]]==0)
            dfsA(mapA[v][i]);
    path[cnt++]=v;
}

void dfsB(int v){//ÔÚ·´Í¼ÉÏDFS£¬ÕÒ³öËùÓÐµãËùÊôµÄSCC±êºÅ£¬´æÈëbelong[]
    vist[v]=1;
    belong[v] = c_id;//ÓÃc_id¶ÔÁªÍ¨·ÖÁ¿½øÐÐ±àºÅ¡£
    for(int i=0;i<mapB[v].size();i++)
        if(vist[mapB[v][i]]==0)
            dfsB(mapB[v][i]);
}

bool check(int ans)    //2-SATÖ÷Ìå,¼ìÑéansÊÇ·ñÎª¿ÉÐÐ´ð°¸
{
    for(int i=0;i<2*n;i++){//Á½ÕÅÍ¼Çå¿Õ
        mapA[i].clear();
        mapB[i].clear();
    }
   
    for(int i=0;i<ans;i++)//½¨Í¼¡£ µ±ÃÅÒªÇóµÄÔ¿³×ÊÇa»òbÊ±£¬ÎÒÃÇ¾ÍÌíÖÃ~a->b,~b->a
    {//°ÑÇ°ans¸öÃÅµÄÔ¿³×£¬½¨³ÉÒ»ÕÅÍ¼¡£
        mapA[dr[i].x].push_back(opp[dr[i].y]);
        mapA[dr[i].y].push_back(opp[dr[i].x]);
        mapB[opp[dr[i].y]].push_back(dr[i].x);
        mapB[opp[dr[i].x]].push_back(dr[i].y);
    }
   
    memset(vist,0,sizeof(vist));
    cnt=0;
    for(int i=0;i<2*n;i++)
        if(vist[i]==0)
            dfsA(i);

    memset(vist,0,sizeof(vist));       
    c_id=1;
    for(int i=cnt-1;i>=0;i--)
        if(vist[path[i]]==0){
            c_id++;
            dfsB(path[i]);
        }

    for(int i=0;i<2*n;i++)
        if(belong[i] == belong[opp[i]])//·¢ÏÖÃ¬¶Ü£¬Õû¸öSCC²»³ÉÁ¢
            return false;
    return true;
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            opp[a]=b;opp[b]=a;
        }
        for(int i=0;i<m;i++)
            scanf("%d%d",&dr[i].x,&dr[i].y);
        int left=1, right=m, mid;
        while(left<right)// ¶þ·Ö´ð°¸£¡£¡
        {
            mid = (left + right)/2;
            if(check(mid))
                left = mid+1;
            else
                right = mid-1;
        }
        cout<<left<<endl;
    }
    return 0;
}
