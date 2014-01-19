#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[5];

struct node{
	int suit;
	int num;
	bool operator <(const node &a)const{
		return a.num > num;
	}
}nod[6];

int get_num(char ch){
	if(ch<='9'&&ch>'0')
		return ch-'0';
	if(ch=='A')
		return 1;
	if(ch=='X')
		return 10;
	if(ch=='J')
		return 11;
	if(ch=='Q')
		return 12;
	return 13;
}

int get_score(){
	int flag=0;
	for(int i=1;i<5;i++){
		if(nod[i].suit!=nod[i-1].suit){
			flag=1;
			break;
		}
	}
	if(!flag){
		int up=0;
		for(int i=1;i<5;i++){
			if(nod[i].num!=nod[i-1].num+1){
				up=1;
				break;
			}
		}
		if(!up)return 1000;
		if(nod[0].num==1&&nod[1].num==10&&nod[2].num==11&&nod[3].num==12&&nod[4].num==13)
			return 1000;
		return 350;
		
	}
	else{
		int same1=0, same2=0;
		for(int i=1;i<4;i++){
			if(nod[i].num!=nod[i-1].num){
				same1=1;
			}
			if(nod[i].num!=nod[i+1].num){
				same2=1;
			}
		}
		if(!same1||!same2)return 750;
		same1=nod[0].num;
		if(nod[1].num==same1&&nod[2].num==same1&&nod[3].num==nod[4].num)
			return 500;
		if(nod[1].num==same1&&nod[2].num==nod[3].num&&nod[2].num==nod[4].num)
			return 500;
		
		same1=0;
		for(int i=1;i<5;i++){
			if(nod[i].num!=nod[i-1].num+1){
				same1=1;
				break;
			}
		}
		if(!same1)return 250;
		if(nod[0].num==1&&nod[1].num==10&&nod[2].num==11&&nod[3].num==12&&nod[4].num==13)
			return 250;
		
		if(nod[0].num==nod[1].num&&nod[0].num==nod[2].num)
			return 200;
		if(nod[1].num==nod[2].num&&nod[1].num==nod[3].num)
			return 200;
		if(nod[2].num==nod[3].num&&nod[2].num==nod[4].num)
			return 200;
		
		
		if(nod[0].num==nod[1].num&&nod[2].num==nod[3].num)
			return 100;
		if(nod[0].num==nod[1].num&&nod[4].num==nod[3].num)
			return 100;
		if(nod[2].num==nod[1].num&&nod[4].num==nod[3].num)
			return 100;
		
		if(nod[0].num==nod[1].num)return 50;
		if(nod[1].num==nod[2].num)return 50;
		if(nod[2].num==nod[3].num)return 50;
		if(nod[3].num==nod[4].num)return 50;
		return 0;
	}
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		for(int i=0;i<5;i++){
			scanf("%s", str);
			nod[i].suit=str[0];
			nod[i].num=get_num(str[1]);
		}
		sort(nod, nod+5);
		//for(int i=0;i<5;i++){
		//	printf("%d %d\n", nod[i].suit, nod[i].num);
		//}
		printf("%d\n", get_score());
	}
	return 0;
}
