class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		if (n == 0) {
			ans.push_back(0);
		} else if (n >= 1) {
			ans.push_back(0);
			ans.push_back(1);
		}
		int fic = 2;
		for (int i = 1; i < n; i++) {
			int n = ans.size();
			for (int j = n - 1; j >= 0; j--) {
				ans.push_back(ans[j]);
			}
			for (int j = 0; j < n; j++) {
				ans[j + n] += fic;
			}
			fic *= 2;
		}
		return ans;
	}
};
