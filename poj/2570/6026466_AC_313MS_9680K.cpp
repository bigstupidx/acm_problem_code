#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,map[27][300][300],flag[30];
int main()
{
    while(scanf("%d",&n),n)
    {
        char str[30];
        int x,y,len;
        memset(map,0,sizeof(map));
        memset(flag,0,sizeof(flag));
        while(scanf("%d%d",&x,&y),x||y)
        {
            scanf("%s",str);
            len=strlen(str);
            for(int i=0;i<len;i++){
                map[str[i]-'a'][x][y]=1;
                flag[str[i]-'a']=1;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(!flag[i])continue;
            for(int w=1;w<=n;w++){
                for(int u=1;u<=n;u++){
                    if(map[i][u][w]){
                        for(int v=1;v<=n;v++){
                            if(map[i][w][v]){
                                map[i][u][v]=1;
                            }
                        }
                    }
                }
            }
        }
        while(scanf("%d%d",&x,&y),x||y)
        {
            bool out=false;
            for(int i=0;i<26;i++)
            {
                if(flag[i]&&map[i][x][y]){
                    out=true;
                    putchar(i+'a');
                }
            }
            if(!out)putchar('-');
            printf("\n");
        }
        puts("");        
    }
    return 0;
}
