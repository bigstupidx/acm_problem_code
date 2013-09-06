#include<stdio.h>
#define MAXN 100010
struct inode{
	int a,sit,lc,rc;
}a[MAXN];
int map[18][MAXN];
void rmq_make(int n)
{
    int i=0,j,t=1;
    while (t*=2,i++,t<=n)
        for (j=t;j<=n;j++) map[i][j]=map[i-1][j]>map[i-1][j-t/2]?map[i-1][j]:map[i-1][j-t/2];
}
int rmq_check(int a,int b)
{
    int i=0,l=b-a+1,t=1;   
    while (t*2<=l) {i++;t*=2;}
    return map[i][a+t-1]>map[i][b]?map[i][a+t-1]:map[i][b];
}
int main()
{
	int m,n,x,y;
	//freopen("c:\\input.txt","r",stdin);
	while (scanf("%d",&n),n) {
		scanf("%d",&m);
		int j=0;
		a[0].a=a[n+1].a=MAXN+MAXN;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i].a);
			if (a[i].a!=a[i-1].a) {
				a[i].sit=++j;
				a[i].lc=1;
			}
			else {
				a[i].sit=j;
				a[i].lc=a[i-1].lc+1;
			}
		}
		int k=j;
		j++;
		for (int i=n;i>=1;i--) {
			if (a[i].a!=a[i+1].a) {
				a[i].sit=--j;
				map[0][j]=a[i].lc;
				a[i].rc=1;
			}
			else {
				a[i].sit=j;
				a[i].rc=a[i+1].rc+1;
			}
		}
		rmq_make(k);
		while (m--) {
			scanf("%d%d",&x,&y);
			int ans=0;
			if (a[y].sit==a[x].sit) ans=a[y].lc-a[x].lc+1;
			else {
				if (a[y].sit-a[x].sit>1) ans=rmq_check(a[x].sit+1,a[y].sit-1);
				ans>?=a[x].rc;ans>?=a[y].lc;
			}
			printf("%d\n",ans);
		}
		
	}
}
