#include<stdio.h>
char str[2010];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%s",str+i);/*½ÓÊÕ·½Ê½²»Í¬*/
		int i=0, j=n-1, cnt=0, x, y;
		while(i<j){
			x=i;y=j;
			while(x<=y)
			{
				if(str[x]<str[y]){
					printf("%c",str[i]);
					i++;
					break;
				}
				else if(str[x]>str[y]){
					printf("%c",str[j]);
					j--;
					break;
				}
				x++;y--;
			}
			if(x>y){
				printf("%c",str[i]);
				i++;
			}
			if(cnt%80==79)printf("\n");
			cnt++;
		}
		printf("%c\n",str[i]);
	}
	return 0;
}
