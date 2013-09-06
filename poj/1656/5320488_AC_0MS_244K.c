#include<stdio.h>
#include<string.h>
int grid[102][102];
int main()
{
	int t;
	scanf("%d",&t);
	memset(grid,0,sizeof(grid));
	while(t--){
		int x,y,l;
		int i,j;
		char ss[10];
		scanf("%s%d%d%d",ss,&x,&y,&l);
		if(!strcmp(ss,"BLACK")){
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
						grid[i][j]=1;
		}
		else if(!strcmp(ss,"WHITE")){
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					grid[i][j]=2;
		}
		else{
			int ans=0;
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					if(grid[i][j]==1)ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}