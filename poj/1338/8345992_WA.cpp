#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int arr[1502], n;

void pre_done() {
	int top = 0;
	arr[0] = 0;
	priority_queue<int> Q;
	Q.push(-1);
	while (top < 1502) {
		while (Q.top() == arr[top])
			Q.pop();
		arr[++top] = Q.top();
		Q.pop();
		Q.push(arr[top] * 2);
		Q.push(arr[top] * 3);
		Q.push(arr[top] * 5);
		//printf("%d\n", arr[top]);
	}
}

int main() {
	pre_done();
	while (scanf("%d", &n), n) {
		printf("%d\n", -arr[n]);
	}
	return 0;
}
