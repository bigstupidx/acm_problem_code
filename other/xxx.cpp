#include <cstdio>
#include <cstdlib>

class ex{
	public: int x, y;
}mp[3000];

struct node{
	int x, y;
}edge[3000000], *x;

int main(){
	ex *p = new ex();
	p.x = 3;
	p.y = 3;
	x = new node();
	for(int i = 0;i<3;i++){
		mp[i].x = 0;
		mp[i].y = 0;
		edge[i].x = i;
		edge[i].y = i;
		printf("%d %d\n", edge[0].x, edge[0].y);
	}
	system("pause");
	return 0;
}
