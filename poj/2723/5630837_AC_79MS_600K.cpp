#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 4000;

vector<int> mapA[MAXN],mapB[MAXN]; //mapB是mapA的反向图
struct{int x,y;}dr[MAXN];   //记录door上的两把锁
int opp[MAXN]; //opp[i]表示与i冲突的元素。即同组的钥匙。

bool vist[MAXN];    //dfs用
int path[MAXN];     //dfs用，存路径
int belong[MAXN];   //dfs用，存各点所属的SCC号

int n,m,cnt,c_id;   //cnt用以路径计数、c_id为连通分量的标号


void dfsA(int v){ //针对2N个钥匙结点，进行DFS。遍历所有联通分量
    vist[v]=1;
    for(int i=0;i<mapA[v].size();i++)
        if(vist[mapA[v][i]]==0)
            dfsA(mapA[v][i]);
    path[cnt++]=v;
}

void dfsB(int v){//在反图上DFS，找出所有点所属的SCC标号，存入belong[]
    vist[v]=1;
    belong[v] = c_id;//用c_id对联通分量进行编号。
    for(int i=0;i<mapB[v].size();i++)
        if(vist[mapB[v][i]]==0)
            dfsB(mapB[v][i]);
}

bool check(int ans)    //2-SAT主体,检验ans是否为可行答案
{
    for(int i=0;i<2*n;i++){//两张图清空
        mapA[i].clear();
        mapB[i].clear();
    }
   
    for(int i=0;i<ans;i++)//建图。 当门要求的钥匙是a或b时，我们就添置~a->b,~b->a
    {//把前ans个门的钥匙，建成一张图。
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
        if(belong[i] == belong[opp[i]])//发现矛盾，整个SCC不成立
            return false;
    return true;
}

void input(){
    int a,b;
    for(int i=0;i<n;i++){//n把钥匙
        cin>>a>>b;
        opp[a] = b;//opp表示分组，矛盾点
        opp[b] = a;
    }
    for(int i=0;i<m;i++)//门信息存入dr[]
        cin>>dr[i].x>>dr[i].y;
   
}

int main(){
    while(cin>>n>>m&&m){//锁子组数、门数
        input();
       
        int left=1, right=m, mid;//r为最多开启门数，初始化为M个门 。r=rigth l=left
        while(left<right)// 二分答案！！
        {
            if(left==right-1){
                if(!check(right))
                    right = left;
                break;
            }
            mid = (left + right)/2;
            if(check(mid))
                left = mid;//若k可行，说明最大解在右边，故left赋为k
            else
                right = mid-1;//否则，最大解必在左边，right赋为k
        }
        cout<<right<<endl;
    }
    return 0;
}