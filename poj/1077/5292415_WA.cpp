#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;

struct num{
	int arrey[10];
	int diff;
	int k;
	char ans[3000];
};
int hash_table[362881];
int start[10],top=0;
int fi[10]={0,1,2,6,24,120,720,5040,40320};

bool operator<(num a,num b)
{
	return a.diff>b.diff;
}

int check()
{
	int i,j,ans=0;
	for(i=1;i<9;i++)
		for(j=i+1;j<10;j++)
			if(start[j]<start[i])
				ans++;
	return ans%2;
}
int Hash(int *x)
{
	int i,j,xx[10],ans=0;
	memset(xx,0,sizeof(xx));
	xx[1]=0;
	for(i=2;i<10;i++)
		for(j=1;j<i;j++)
			if(x[i]<x[j])
				xx[i]++;
	for(i=1;i<9;i++)
		ans+=fi[i-1]*xx[i];
	ans+=(9-x[9])*fi[8];
	return ans;
}
int difference(int *x)
{
	int i,ans=0;
	for(i=1;i<10;i++)
		ans+=abs(x[i]-i);
	return ans;
}
int Equal(int *x)
{
	for(int i=1;i<10;i++)
		if(x[i]!=i)
			return 0;
	return 1;
}
void bfs()
{
	priority_queue<num>q;
	num next,head,temp;
	for(int i=1;i<10;i++)
		head.arrey[i]=start[i];
	head.diff=difference(head.arrey);
	head.k=-1;
	q.push(head);
	while(q.size()){
		temp=q.top();
		q.pop();
		hash_table[Hash(temp.arrey)]=1;
		if(Equal(temp.arrey)){
			temp.ans[temp.k+1]='\0';
			printf("%s\n",temp.ans);
			return ;
		}
		temp.ans[temp.k+1]='\0';
		for(int i=0;i<4;i++)
		{
			int t,xxx=temp.arrey[9];
			for(int j=1;j<10;j++)
				next.arrey[j]=temp.arrey[j];
			next.k=temp.k+1;
			strcpy(next.ans,temp.ans);
			switch(i){
			case 0:
				if(xxx%3==1)
					   continue;
				next.arrey[9]--;
				next.ans[next.k]='l';
				break;
			case 1:
				if(xxx%3==0)
					continue;
				next.arrey[9]++;
				next.ans[next.k]='r';
				break;
			case 2:
				if(xxx<4)
					continue;
				t=next.arrey[xxx-3];
				next.arrey[xxx-3]=next.arrey[xxx-2];
				next.arrey[xxx-2]=next.arrey[xxx-1];
				next.arrey[xxx-1]=t;
				next.arrey[9]-=3;
				next.ans[next.k]='u';
				break;
			case 3:
				if(xxx>6)
					continue;
				t=next.arrey[xxx+2];
				next.arrey[xxx+2]=next.arrey[xxx+1];
				next.arrey[xxx+1]=next.arrey[xxx];
				next.arrey[xxx]=t;
				next.arrey[9]+=3;
				next.ans[next.k]='d';
				break;
			}
			if(!hash_table[Hash(next.arrey)]){
				next.diff=difference(next.arrey);
				q.push(next);
			}
		}
	}
	return ;
}

int main()
{
	char str[4];
	int j,k=1;
	for(int i=1;i<10;i++){
		scanf("%s",str);
		if(str[0]=='x')
			j=i;
		else
			start[k++]=str[0]-'0';
	}
	start[k]=j;
	if(!check()){
		memset(hash_table,0,sizeof(hash_table));
		bfs();
	}
	else
		printf("unsolvable\n");
	return 0;
}