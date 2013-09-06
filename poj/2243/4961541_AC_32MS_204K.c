#include<stdio.h>
#include<string.h>

int chess[9][9];
int beginrow,begincol;
int endrow,endcol;
int path[65];

int bfs(int row,int col)
{
	int currow,curcol;
	int nextrow,nextcol;
	int l=1,i,j;

	chess[row][col]=0;
	path[0]=row*8+col;

	for(i=0;i<l;i++){
		currow=path[i]/8;
		curcol=path[i]%8;
		for(j=1;j<=8;j++){
			switch(j){
			case 1:
				nextrow = currow + 2;
				nextcol = curcol - 1;
				break;
			case 2:
				nextrow = currow + 1;
				nextcol = curcol - 2;
				break;
			case 3:
				nextrow = currow - 1;
				nextcol = curcol - 2;
				break;
			case 4:
				nextrow = currow - 2;
				nextcol = curcol - 1;
				break;
			case 5:
				nextrow = currow - 2;
				nextcol = curcol + 1;
				break;
			case 6:
				nextrow = currow - 1;
				nextcol = curcol + 2;
				break;
			case 7:
				nextrow = currow + 1;
				nextcol = curcol + 2;
				break;     
			case 8:
				nextrow = currow + 2;
				nextcol = curcol + 1;
				break;
			}

			if(nextrow>=0&&nextrow<8&nextcol>=0&&nextcol<8)
			{
				if(chess[nextrow][nextcol]==-1)
				{
					if(nextrow==endrow&&nextcol==endcol)
						return chess[currow][curcol]+1;
					else{
						chess[nextrow][nextcol]=chess[currow][curcol]+1;
						path[l++]=nextrow*8+nextcol;
					}
				}
			}
		}
	}
}

int main()
{
	char a[3],b[3];
	while(scanf("%s%s",a,b)!=EOF){
		int step;
		if(strcmp(a,b)==0){
			printf("To get from %s to %s takes 0 knight moves.\n",a,b);
			continue;
		}

		beginrow=a[0]-'a';
		begincol=a[1]-'1';

		endrow=b[0]-'a';
		endcol=b[1]-'1';

		memset(chess,-1,sizeof(chess));
		memset(path,0,sizeof(path));

		step=bfs(beginrow,begincol);
		printf("To get from %s to %s takes %d knight moves.\n",a,b,step);
	}
return 0;
}
