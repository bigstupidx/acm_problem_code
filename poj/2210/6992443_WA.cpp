#include <cstdio>
#include <cstring>

int flag[50002], mon[2][13]={
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool is_leap(int year){
	if(year%4||!(year%100)&&(year%400)){
		return false;
	}
	return true;
}

void pre_done(){
	memset(flag, 0, sizeof(flag));
	flag[2000]=1;
	for(int i=2001;i<50002;i++){
		if(is_leap(i)){
			flag[i]=1;
		}
	}
	return ;
}

int main(){
	int nca;
	pre_done();
	scanf("%d", &nca);
	while(nca--){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		hh=hh*3600+mm*60+ss;
		hh=(int)(hh*10.0/8.64);
		printf("%d:%d:%d ", hh/10000, (hh%10000)/100,hh%100);
		
		scanf("%d.%d.%d", &hh, &mm, &ss);
		int day=0, ii=0;
		for(int i=2000;i<ss;i++){
			if(flag[i]){
				day+=366;	
			}
			else{
				day+=365;
			}
		}
		if(flag[ss])ii=1;
		for(int i=1;i<mm;i++){
			day+=mon[ii][i];
		}
		day+=hh-1;
		printf("%d.%d.%d\n",(day%100)+1, ((day%1000)/100)+1, (day/1000)); 
	}
	return 0;
}
