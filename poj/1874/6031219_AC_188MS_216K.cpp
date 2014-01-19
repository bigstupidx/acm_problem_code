/*
学辉牛码
*/
#include <cstdio>
#include <cstring>
#define Max(a,b) (a>b?a:b)
bool c[51][1001];
int main()
{
    int w , test = 0 , b, x ,f[21];
    while(scanf("%d",&w),w){
        if(test) printf("\n");
        memset(c,0,sizeof(c));
        c[0][0] = 1 , f[0] = 0;
        int sum = 0;
        for(int k = 1;k<=w;k++){
            scanf("%d",&b);
            for(int i = 1;i<=b;i++){
                scanf("%d",&x);
                f[i] = f[i-1] - x + 10;
            }
            int m = 0;
            for(int i = 1;i<=b;i++) m = Max(m,f[i]);
            sum += m;
            for(int i = 0;i<=b;i++) if(f[i] == m)
                for(int j = i;j<=1000;++j)
                    if(!c[k][j] && c[k-1][j-i]) c[k][j] = 1;
        }
        printf("Workyards %d\nMaximum profit is %d.\nNumber of pruls to buy:",++test,sum);
        for(int j = 0,cc = 0;j<=1000 && cc<10;j++)if(c[w][j]) cc++,printf(" %d",j);
        printf("\n");
    }
    return 0;
}