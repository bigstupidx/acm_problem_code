#include<stdio.h>
#include<string.h>
char in[100][100];
int count;
int t=1;

int issuffix(int j,int i)
{
	int r;
	for(r=0;in[j][r]&&in[i][r];r++)
		if(in[j][r]!=in[i][r])return 0;
	if(!in[j][r]||!in[i][r])
		return 1;
}
void solve()
{
	int i,j;
	for(i=0;i<count-1;i++)
		for(j=i+1;j<count;j++)
			if(issuffix(j,i)){
				count=0;
				printf("Set %d is not immediately decodable\n",t);
				t++;
				return ;
			}
	count=0;
	printf("Set %d is immediately decodable\n",t);
	t++;
	return ;
}

int main()
{
	while(1){
		for(count=0;;count++){
			scanf("%s",in[count]);
			if(strcmp(in[count],"9")==0)
				break;
		}
		count++;
		solve();
	}
	return 0;
}
	
