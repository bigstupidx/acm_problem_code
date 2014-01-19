class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxi = 0, temp_max = 0, len = s.length();
		map<char, int> mp;
		map<char, int>::iterator p;
		for (int i = 0; i < len; i++) {
			char ch = s[i];
			p = mp.find(ch);
			if (p == mp.end()) {
				++temp_max;
				mp.insert(make_pair(ch, i));
			} else {
				if (p->second < i - temp_max) {
					++temp_max;
				} else {
					temp_max = i - p->second;
				}
				p->second = i;
			}
			if (temp_max > maxi)
				maxi = temp_max;
		}
		return maxi;
	}
};
