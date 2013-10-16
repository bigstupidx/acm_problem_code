#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

__int64 arr[1502];
int n;

void pre_done() {
	priority_queue<__int64> Q;
	Q.push(-1);
	arr[0] = 0;
	int top = 0;
	while (top < 1501) {
		while (Q.top() == arr[top])
			Q.pop();
		arr[++top] = Q.top();
		Q.pop();
		Q.push(arr[top] * 2);
		Q.push(arr[top] * 3);
		Q.push(arr[top] * 5);
	}
	return;
}

int main() {
	pre_done();
	while (scanf("%d", &n), n) {
		printf("%I64d\n", -arr[n]);
	}
	return 0;
}
