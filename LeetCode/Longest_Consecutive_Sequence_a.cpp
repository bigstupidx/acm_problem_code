class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		sort(num.begin(), num.end());
		int maxi = 1;
		for (int i = 1, temp = 1, n = num.size(); i < n; i++) {
			if (num[i] == num[i - 1] + 1) {
				++temp;
			} else if (num[i] == num[i - 1]) {
			} else {
				temp = 1;
			}
			if (temp > maxi)
				maxi = temp;
		}
		return maxi;
	}
};
