
#include<stdio.h>
#define MAXN 100010

struct inode{
	int a,sit,lc,rc;
}a[MAXN];

/*char yc[MAXN];int fyc[20]={1};*/
int map[18][MAXN];

void rmq_make(int n)
{
    int i=0,j,t=1;
    while (t*=2,i++,t<=n)
        for (j=t;j<=n;j++)
			map[i][j]=map[i-1][j]>map[i-1][j-t/2]?map[i-1][j]:map[i-1][j-t/2];
}
int rmq_check(int a,int b)
{
    int l=b-a+1,t=1,i=0;
    /*int i=yc[l],t=fyc[yc[l]];*/
    while (t*2<=l) {i++;t*=2;}
    return map[i][a+t-1]>map[i][b]?map[i][a+t-1]:map[i][b];
}
/*int getnum()
{
    char ch;
    while (ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while ((ch=getchar()),(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
/*int fgetnum()
{
    char ch;
    while (ch=getchar(),ch==10||ch==32);
    bool fh;
    int ans=ch-48;
	if (ch=='-') {fh=1;ans=0;}
	else fh=0;
    while ((ch=getchar()),(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    if (fh) return -ans;
    return ans;
}*/
int main()
{
	int m,n,x,y;
	/*for (int i=1;i<20;i++) 
		fyc[i]=fyc[i-1]*2;
	for (int i=0;i<MAXN;i++) 
		if (i==fyc[yc[i-1]+1]) 
			yc[i]=yc[i-1]+1;
		else yc[i]=yc[i-1];
	*/
	while (scanf("%d",&n),n) {
		int j=0,i,k;
		a[0].a=a[n+1].a=MAXN+MAXN;
		scanf("%d",&m);
		for (i=1;i<=n;i++) {
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
		k=j;
		/*j++;*/
		for (i=n;i>=1;i--) {
			if (a[i].a!=a[i+1].a) {
				/*a[i].sit=--j;*/
				map[0][j--]=a[i].lc;
				a[i].rc=1;
			}
			else {
			/*	a[i].sit=j;*/
				a[i].rc=a[i+1].rc+1;
			}
		}
		rmq_make(k);
		while (m--) {
			int ans=0;
			scanf("%d%d",&x,&y);
			if (a[y].sit==a[x].sit) ans=a[y].lc-a[x].lc+1;
			else {
				if (a[y].sit-a[x].sit>1) ans=rmq_check(a[x].sit+1,a[y].sit-1);
				if(ans<a[x].rc)ans=a[x].rc;
				if(ans<a[y].lc)ans=a[y].lc;
			}
			printf("%d\n",ans);
		}
		
	}
	return 0;
}
