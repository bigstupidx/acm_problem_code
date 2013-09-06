#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

int aa[2][16], flag[16], mark[80000], A, B, C, S;

int main()
{
	while(scanf("%d",&A), A){
		memset(flag, -1, sizeof(flag));
		memset(mark,  0, sizeof(mark));
		scanf("%d%d%d", &B, &C, &S);
		int tem = S, j = 0, now = 0;
		memset(aa, 0, sizeof(aa));
		while(tem){
			aa[0][j++]=tem%2;
			tem/=2;
		}
		while(!mark[S]){
			mark[S]=1;
			now = 1 - now;
			S = (A*S + B) % C;
			memset(aa[now], 0, sizeof(aa[now]));
			tem=S;	j=0;
			while(tem){
				aa[now][j++]=tem%2;
				tem/=2;
			}
			for(int i=0;i<16;i++){
				if(flag[i]==-1){
					if(aa[now][i]!=aa[1-now][i]){
						flag[i]=0;
					}
				}
			}
			//printf("%d ", S);
			//system("pause");
		}
		for(int i=15;i>=0;i--){
			if(flag[i]==-1)
				printf("%d", aa[now][i]);
			else
				putchar('?');
		}
		puts("");
	}
	return 0;
}
