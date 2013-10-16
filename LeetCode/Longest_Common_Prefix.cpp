class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1) {
			return strs[0];
		}
		int len = strs[0].length();
		int ans = 0;
		for (int i = 0; i < len; i++) {
			char ch = strs[0][i];
			bool flag = true;
			for (int j = 1; j < strs.size(); j++) {
				if (i < strs[j].length() && strs[j][i] == ch) {
				} else {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			} else {
				ans = i + 1;
			}
		}
		return strs[0].substr(0, ans);
	}
};
