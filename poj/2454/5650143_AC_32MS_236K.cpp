#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int w,p;
};
node n[185];
bool cmp(node n1,node n2){
	return n1.w>n2.w;
}
int main(){
	int k,i,j,s1=0,s2=0,index[185],temp;
	cin>>k;
	for (i=1;i<=3*k;i++){
		cin>>n[i].w;
		n[i].p=i;
	}
	sort(n+1,n+1+3*k,cmp);
	srand(16141);
	for (i=1;i<=3*k;i++)
		index[i]=i;
	while (1){
		i=rand()%(2*k)+1;
		j=rand()%(2*k)+1;
		temp=index[i];
		index[i]=index[j];
		index[j]=temp;
		s1=0;
		for (i=1;i<=k;i++)
			s1+=n[index[i]].w;
		if (s1<=500*k) continue;
		s2=0;
		for (i=k+1;i<=2*k;i++)
			s2+=n[index[i]].w;
		if (s2<=500*k) continue;
		break;
	}
	for (i=1;i<=3*k;i++)
		printf("%d\n",n[index[i]].p);
	return 0;
}