#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int arrey[102][102];
int sum[102];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int r,c,x,y,i;
		__int64 temp,min,blocks;
		blocks=0;
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&x,&y);
		for(r=1;r<=y;r++)
			for(c=1;c<=x;c++)
				scanf("%d",&arrey[r][c]);
		for(c=1;c<=x;c++)
			for(r=1;r<=y;r++)
				sum[c]+=arrey[r][c];
		min=1000000000;
		for(c=1;c<=x;c++){
			temp=0;
			for(i=1;i<=x;i++)
					temp+=(abs(i-c))*sum[i];
			if(temp<min)
				min=temp;
		}
		blocks=min;
		memset(sum,0,sizeof(sum));
		for(r=1;r<=y;r++)
			for(c=1;c<=x;c++)
				sum[r]+=arrey[r][c];
		min=1000000000;
		for(r=1;r<=y;r++){
			temp=0;
			for(i=1;i<=y;i++)
					temp+=(abs(i-r))*sum[i];
			if(temp<min)
				min=temp;
		}
		blocks+=min;
		printf("%I64d\n",blocks);
	}
	return 0;
}


