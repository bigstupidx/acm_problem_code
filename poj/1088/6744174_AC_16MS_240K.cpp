#include <cstdio>
#include <cstring>
int n,m,map[102][102],ans[102][102],dir[4][2]={-1,0,1,0,0,-1,0,1};
int DFS(int ii,int jj){
    if(ans[ii][jj]!=-1)return ans[ii][jj];
    int maxi=0;
    for(int k=0;k<4;k++){
        int i=ii+dir[k][0];
        int j=jj+dir[k][1];
        if(i>0&&i<=n&&j<=m&&j>0&&map[i][j]>map[ii][jj]){
            int tem=DFS(i,j);
            if(maxi<tem)
                maxi=tem;
        }
    }
    return ans[ii][jj]=maxi+1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
            }
        }
        memset(ans,-1,sizeof(ans));
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int tem=DFS(i,j);
                if(tem>maxi)maxi=tem;
            }
        }
        printf("%d\n",maxi);
    }
    return 0;
}
