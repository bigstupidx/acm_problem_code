#include <cstdio>
#include <cstring>
char str[2][1010];
int ans[1010][1010];
int MAX(int x,int y){
    if(x>y)return x;
    return y;
}
int main()
{
    while(scanf("%s%s",str[0],str[1])!=EOF){
        int len1=strlen(str[0]);
        int len2=strlen(str[1]);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<len2;i++)
            if(str[1][i]==str[0][0])
                ans[0][i]=1;
                
        for(int i=0;i<len1;i++)
            if(str[0][i]==str[1][0])
                ans[i][0]=1;
                
        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                int x1=ans[i-1][j];
                int x2=ans[i][j-1];
                ans[i][j]=MAX(x1,x2);
                if(str[0][i]==str[1][j]){
                    int x3=ans[i-1][j-1]+1;
                    ans[i][j]=MAX(x3,ans[i][j]);
                }
            }
        }
        printf("%d\n",ans[len1-1][len2-1]);
    }
    return 0;
}
