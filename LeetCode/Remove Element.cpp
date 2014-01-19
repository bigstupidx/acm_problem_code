#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		int ans = 0;
		for (int j = 0, i = 0; i < n; i++) {
			if (elem != A[i]) {
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
