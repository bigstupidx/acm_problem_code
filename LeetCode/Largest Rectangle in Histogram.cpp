#include <cstdio>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int n = height.size();
		if (n == 0)
			return 0;

		vector<int> pre;
		pre.reserve(n);
		{
			stack<int> st;
			st.push(0);
			pre[0] = -1;
			for (int i = 1; i < n; i++) {
				while (!st.empty() && height[st.top()] >= height[i])
					st.pop();
				if (!st.empty())
					pre[i] = st.top();
				else
					pre[i] = -1;
				st.push(i);
			}
		}

		vector<int> next;
		next.reserve(n);
		{
			stack<int> st;
			st.push(n - 1);
			next[n - 1] = n;
			for (int i = n - 2; i >= 0; i--) {
				while (!st.empty() && height[st.top()] >= height[i])
					st.pop();
				if (!st.empty())
					next[i] = st.top();
				else
					next[i] = n;
				st.push(i);
			}
		}
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, (next[i] - pre[i] - 1) * height[i]);
		}
		return maxi;
	}
};

int main() {
	return 0;
}
