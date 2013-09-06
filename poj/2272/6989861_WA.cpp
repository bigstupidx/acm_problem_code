#include <cstdio>
#include <cmath>
#include <cstring>

struct node{
	double x, y;
	int score;
}nod[2][3];

int main(){
	double tem;
	while(scanf("%lf", &tem),tem!=-100){
		nod[0][0].x=tem;
		scanf("%lf", &nod[0][0].y);
		for(int i=1;i<3;i++){
			scanf("%lf%lf", &nod[0][i].x, &nod[0][i].y);
		}
		for(int i=0;i<3;i++){
			scanf("%lf%lf", &nod[1][i].x, &nod[1][i].y);
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				double ax=nod[i][j].x;
				double by=nod[i][j].y;
				tem=sqrt(ax*ax+by*by);
				if(tem<=3)nod[i][j].score=100;
				else if(tem<=6)nod[i][j].score=80;
				else if(tem<=9)nod[i][j].score=60;
				else if(tem<=12)nod[i][j].score=40;
				else if(tem<=15)nod[i][j].score=20;
				else nod[i][j].score=0;
				printf("%d %d %d\n", i+1, j+1, nod[i][j].score);
			}
		}
		int x=(int)(nod[0][0].score+nod[0][1].score+nod[0][2].score);
		int y=(int)(nod[1][0].score+nod[1][1].score+nod[1][2].score);
		if(x==y){
			printf("SCORE: %d to %d, TIE.\n", x, x);
		}
		else{
			if(x>y){
				printf("SCORE: %d to %d, PLAYER 1 WINS.\n", x, y);
			}
			else{
				printf("SCORE: %d to %d, PLAYER 2 WINS.\n", x, y);
			}
		}
	}
	return 0;
}
