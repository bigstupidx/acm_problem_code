#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node{
	int id;
	int r, c;
}nod[2][80];

bool op1(const node &a, const node &b){
	if(a.id==b.id){
		if(a.r==b.r){
			return a.c < b.c;
		}
		return a.r < b.r;
	}
	return a.id < b.id;
}

bool op2(const node &a, const node &b){
	if(a.id==b.id){
		if(a.r==b.r){
			return a.c < b.c;
		}
		return a.r > b.r;
	}
	return a.id < b.id;
}

int num[2];
char str[40];

int main(){
	for(int i=0;i<17;i++){
		gets(str);
		if(i%2){
			for(int j=0;j<33;j++){
				if(j%4==2){
					if(str[j]=='K'){
						nod[0][num[0]].id=1;
						nod[0][num[0]].r=8-i/2;
						nod[0][num[0]].c=j/4;
						num[0]++;
					}
					else if(str[j]=='k'){
						nod[1][num[1]].id=1;
						nod[1][num[1]].r=8-i/2;
						nod[1][num[1]].c=j/4;
						num[1]++;
					}
					else if(str[j]=='Q'){
						nod[0][num[0]].id=2;
						nod[0][num[0]].r=8-i/2;
						nod[0][num[0]].c=j/4;
						num[0]++;
					}
					else if(str[j]=='q'){
						nod[1][num[1]].id=2;
						nod[1][num[1]].r=8-i/2;
						nod[1][num[1]].c=j/4;
						num[1]++;
					}
					else if(str[j]=='R'){
						nod[0][num[0]].id=3;
						nod[0][num[0]].r=8-i/2;
						nod[0][num[0]].c=j/4;
						num[0]++;
					}
					else if(str[j]=='r'){
						nod[1][num[1]].id=3;
						nod[1][num[1]].r=8-i/2;
						nod[1][num[1]].c=j/4;
						num[1]++;
					}
					else if(str[j]=='B'){
						nod[0][num[0]].id=4;
						nod[0][num[0]].r=8-i/2;
						nod[0][num[0]].c=j/4;
						num[0]++;
					}
					else if(str[j]=='b'){
						nod[1][num[1]].id=4;
						nod[1][num[1]].r=8-i/2;
						nod[1][num[1]].c=j/4;
						num[1]++;
					}
					else if(str[j]=='N'){
						nod[0][num[0]].id=5;
						nod[0][num[0]].r=8-i/2;
						nod[0][num[0]].c=j/4;
						num[0]++;
					}
					else if(str[j]=='n'){
						nod[1][num[1]].id=5;
						nod[1][num[1]].r=8-i/2;
						nod[1][num[1]].c=j/4;
						num[1]++;
					}
					else if(str[j]=='P'){
						nod[0][num[0]].id=6;
						nod[0][num[0]].r=8-i/2;
						nod[0][num[0]].c=j/4;
						num[0]++;
					}
					else if(str[j]=='p'){
						nod[1][num[1]].id=6;
						nod[1][num[1]].r=8-i/2;
						nod[1][num[1]].c=j/4;
						num[1]++;
					}
				}
			}
		}
	}
	sort(nod[0],nod[0]+num[0],op1);
	sort(nod[1],nod[1]+num[1],op2);
	for(int j=0;j<2;j++){
		if(j==0){printf("White: K%c%d", nod[0][0].c+'a', nod[0][0].r);}
		else printf("Black: K%c%d", nod[1][0].c+'a', nod[1][0].r);
		for(int i=1;i<num[j];i++){
			if(nod[j][i].id==2){
				printf(",Q%c%d",nod[j][i].c+'a', nod[j][i].r);
			}
			else if(nod[j][i].id==3){
				printf(",R%c%d",nod[j][i].c+'a', nod[j][i].r);
			}
			else if(nod[j][i].id==4){
				printf(",B%c%d",nod[j][i].c+'a', nod[j][i].r);
			}
			else if(nod[j][i].id==5){
				printf(",N%c%d",nod[j][i].c+'a', nod[j][i].r);
			}
			else{
				printf(",%c%d",nod[j][i].c+'a', nod[j][i].r);
			}
		}
		puts("");
	}
	//system("pause");
	return 0;
}
