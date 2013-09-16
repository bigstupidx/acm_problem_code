#include <cstdio>
#include <cstring>

char str[100];
int n, flag[100];

int main()
{
	int nca;
	scanf("%d",&nca);
	while(nca--){
		int k=0, a, b, c;
		scanf("%d",&n);
		scanf("%d", &a);
		for(int i=0;i<a;i++)
			str[k++] = '(';
		str[k++] = ')';
		for(int i=1;i<n;i++){
			scanf("%d",&b);
			c = b - a; a = b;
			for(int j=0; j< c;j++)
				str[k++]='(';
			str[k++]=')';
		}
		memset(flag,0,sizeof(flag));
		for(int i=0;i<k;i++){
			if(str[i]==')'){
				int cnt=0;
				for(int j=i-1;j>=0;j--){
					if(str[j]=='('){
						cnt++;
						if(!flag[j]){
							flag[j]=1;
							break;
						}
					}
				}
				printf("%d ", cnt);
			}
		}
		puts("");
	}
	return 0;
}
