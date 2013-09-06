#include<stdio.h>
#include<queue>
#define MAX 200001
using namespace std;

int flag[MAX];
queue<int>q;
int main()
{
	int n,k,temp;
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==k)
			printf("0\n");
		else{
			q.push(n);
			flag[n]=1;
			while(!q.empty()){
				temp=q.front();
				q.pop();
				if(temp-1>=0&&!flag[temp-1]){
					flag[temp-1]=flag[temp]+1;
					if(temp-1==k)break;
					q.push(temp-1);
				}
				if(temp+1<=100000&&!flag[temp+1]){
					flag[temp+1]=flag[temp]+1;
					if(temp+1==k)break;
					q.push(temp+1);
				}
				if(temp*2<=100000&&!flag[temp*2]){
					flag[temp*2]=flag[temp]+1;
					if(temp*2==k)break;
					q.push(temp*2);
				}
			}
			printf("%d\n",flag[k]-1);
		}
	}
	return 0;
}
