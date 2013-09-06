#include<stdio.h>
#include<stdlib.h>
int puzzle[6][8],press[6][8];

int idetermine()
{
	int r,c;
	for(r=1;r<5;r++)
		for(c=1;c<=6;c++)
			press[r+1][c]=(puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c+1]+press[r][c-1])%2;
	for(c=1;c<=6;c++)
		if((press[5][c-1]+press[5][c]+press[5][c+1]+press[4][c])%2!=puzzle[5][c])
			return 0;
	return 1;
}
void determine()
{
	int c;
	for(c=1;c<=6;c++)
		press[1][c]=0;
	while(!idetermine()){
		press[1][1]++;
		c=1;
		while(press[1][c]>1){
			press[1][c]=0;c++;
			press[1][c]++;
		}
	}
	return ;
}
int main()
{
	int i,t,r,c;
	scanf("%d",&t);
	for(r=0;r<6;r++)
		press[r][0]=press[r][7]=0;
	for(c=1;c<7;c++)
		press[0][c]=0;
	for(i=1;i<=t;i++){
		for(r=1;r<=5;r++)
			for(c=1;c<=6;c++)
				scanf("%d",&puzzle[r][c]);
		determine();
		printf("PUZZLE #%d\n",i);
		for(r=1;r<=5;r++){
			for(c=1;c<=6;c++)
				printf("%d ",press[r][c]);
			printf("\n");
		}
	}
	system("pause");
}