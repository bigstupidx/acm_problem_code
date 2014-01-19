
#include<stdio.h>
int map[17][50001],map2[17][50001];
void rmq_make(int n)
{
    int i=1,j,t=1;
    while (t*=2,i++,t<=n)
        for (j=t;j<=n;j++) {
            map[i][j]=map[i-1][j]<map[i-1][j-t/2]?map[i-1][j]:map[i-1][j-t/2];
            map2[i][j]=map2[i-1][j]>map2[i-1][j-t/2]?map2[i-1][j]:map2[i-1][j-t/2];
        }
}

int rmq_check(int a,int b)
{
    int i=1,l=b-a+1,t=1;
    while (t*2<=l) {i++;t*=2;}
    return (map2[i][a+t-1]>map2[i][b]?map2[i][a+t-1]:map2[i][b])
		-(map[i][a+t-1]<map[i][b]?map[i][a+t-1]:map[i][b]);
}

int main()
{
    int n,c,i,j,a,b;
    scanf("%d%d",&n,&c);
    for (i=1;i<=n;i++) {
		scanf("%d",&map[1][i]);map2[1][i]=map[1][i];}
    rmq_make(n);
    for (i=1;i<=c;i++) {
        scanf("%d%d",&a,&b);
        printf("%d\n",rmq_check(a,b));
    }
}
