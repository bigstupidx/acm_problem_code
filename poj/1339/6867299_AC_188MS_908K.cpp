#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int ans=0, a, b, c, n;
		priority_queue<int>Q;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &a);
			Q.push(-a);
		}
		while(!Q.empty()){
			a=Q.top();Q.pop();
			if(Q.empty())
				break;
			b=Q.top();Q.pop();
			a+=b;
			ans+=a;
			Q.push(a);
		}
		printf("%d\n", -ans);
	}
	return 0;
}
