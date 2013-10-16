#include <cstdio>
#include <cstring>

char str[100], tem[100];
int aa[3],kk[3],arr[3][100];

void my_change(int ii, int n){
	char ch;
	for(int i=0;i<kk[ii];i++)
		tem[i]=str[arr[ii][i]];
	for(int i=0;i<aa[ii];i++){
		ch=tem[kk[ii]-1];
		for(int j=kk[ii]-1;j>0;j--)
			tem[j]=tem[j-1];
		tem[0]=ch;
	}
	for(int i=0;i<kk[ii];i++)
		str[arr[ii][i]]=tem[i];
}

int main()
{
	while(scanf("%d%d%d",&aa[0],&aa[1],&aa[2]), aa[0]||aa[1]||aa[2]){
		scanf("%s", str);
		int len=strlen(str);
		memset(kk,0,sizeof(kk));
		for(int i=0;i<len;i++){
			if(str[i]<='i'&&str[i]>='a')
				arr[0][kk[0]++]=i;
			else if(str[i]<='r'&&str[i]>='j')
				arr[1][kk[1]++]=i;
			else
				arr[2][kk[2]++]=i;
		}
		for(int i=0;i<3;i++)
			my_change(i,len);
		printf("%s\n",str);
	}
	return 0;
}
