#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 1)
			return n;
		int ans = 1;
		for (int j = 1, i = 1; i < n; i++) {
			if (A[i] != A[i - 1]) {
				A[j++] = A[i];
				++ans;
			}
		}
		return ans;
	}
};

int main() {
	return 0;
}
