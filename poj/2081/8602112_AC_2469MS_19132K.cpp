#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int n, arr[500010];

void pre_done() {
	arr[0] = 0;
	set<int> st;
	for (int i = 1; i < 500001; ++i) {
		int a = arr[i - 1] - i;
		if (st.find(a) == st.end() && a > 0) {
			st.insert(a);
			arr[i] = a;
		} else {
			a = arr[i - 1] + i;
			st.insert(a);
			arr[i] = a;
		}
	}
	return;
}

int main() {
	pre_done();
	while (scanf("%d", &n), n != -1) {
		printf("%d\n", arr[n]);
	}
	return 0;
}
