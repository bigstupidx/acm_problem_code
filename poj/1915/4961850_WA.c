#include<stdio.h>
#include<string.h>

int beginrow,begincol;
int endrow,endcol;
int chess[301][301];
int path[100000];
int n;

int bfs(int row,int col)
{
	int currow,curcol;
	int nextrow,nextcol;
	int l=1,i,j;
	
	path[0]=row*n+col;
	chess[row][col]=0;
	for(i=0;i<l;i++){
		currow=path[i]/n;
		curcol=path[i]%n;
		for(j=1;j<=8;j++){
			switch(j){
			case 1:
				nextrow=currow-1;
				nextcol=curcol-2;
				break;
			case 2:
				nextrow=currow-2;
				nextcol=curcol-1;
				break;
			case 3:
				nextrow=currow-1;
				nextcol=curcol+2;
				break;
			case 4:
				nextrow=currow+1;
				nextcol=curcol-2;
				break;
			case 5:
				nextrow=currow+1;
				nextcol=curcol+2;
				break;
			case 6:
				nextrow=currow+2;
				nextcol=curcol-1;
				break;
			case 7:
				nextrow=currow+2;
				nextcol=curcol+1;
				break;
			case 8:
				nextrow=currow-2;
				nextcol=curcol+1;
				break;
			}
			if(nextrow>=0&&nextrow<n&&nextcol>=0&&nextcol<n)
			{
				if(chess[nextrow][nextcol]==-1)
				{
					if(nextrow==endrow&&nextcol==endcol)
						return chess[currow][curcol]+1;
					else
					{
						chess[nextrow][nextcol]=chess[currow][curcol]+1;
						path[l++]=nextrow*n+nextcol;
					}
				}
			}
		}
	}
}

		

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int step;
		
		scanf("%d",&n);
		scanf("%d%d%d%d",&beginrow,&begincol,&endrow,&endcol);
		
		if(beginrow==endrow&&begincol==endcol){
			printf("0\n");
			continue;
		}

		memset(chess,-1,sizeof(chess));
		memset(path,0,sizeof(path));
		
		step=bfs(beginrow,begincol);
		printf("%I64d\n",step);
	}
	return 0;
}
