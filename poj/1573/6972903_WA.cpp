#include <cstdio>
#include <cstring>

char map[120][120];
int n, m, mark[120][120], sx, sy, visit[120][120];

int main(){
	while(scanf("%d%d%d", &n, &m, &sy), n||m||sy){
		
		for(int i=0;i<n;i++){
			scanf("%s", map[i]);
		}
		sx = 0; sy--;
		int flag = 0, step = 0, loop;
		memset(mark, 0,sizeof(mark));
		memset(visit,0,sizeof(visit));
		while(1){
			visit[sx][sy]=1;
			if(map[sx][sy]=='N'){
				sx--;
			}
			else if(map[sx][sy]=='S'){
				sx++;
			}
			else if(map[sx][sy]=='W'){
				sy--;
			}
			else{
				sy++;
			}
			if(sx<0||sx==n||sy<0||sy==m)break;
			if(visit[sx][sy]){
				flag=1;
				loop=step-mark[sx][sy];
				break;
			}
			mark[sx][sy]=step++;
		}
//		printf("%d \n", step);
		if(flag){
			if(step==loop)
				printf("0 step(s) before a loop of %d step(s)\n", loop);
			else
				printf("%d step(s) before a loop of %d step(s)\n", step - loop + 1, loop);
		}
		else{
			printf("%d step(s) to exit\n", step + 1);
		}
	}
	return 0;
}
