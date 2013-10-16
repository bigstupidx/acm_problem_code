class Solution {
public:
	int maxArea(vector<int> &height) {
		if (height.size() <= 1)
			return 0;
		int sum = 0;
		stack<int> st;
		st.push(0);
		for (int j, k, i = 1; i < height.size(); i++) {
			while (st.size() > 0) {
				j = st.top();
				if (height[j] < height[i]) {
					st.pop();
					if (st.size() > 0) {
						k = st.top();
						sum -= (j - k) * height[j];
					}
				} else {
					break;
				}
			}
			if (st.size() == 0) {
				sum += (i - j) * height[j];
			} else {
				sum += (i - j) * height[i];
			}
//			cout << sum << endl;
			st.push(i);
		}
		return sum;
	}
};
