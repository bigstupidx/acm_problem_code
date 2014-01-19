#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length(), maxi = 0;
		string ans;
		for (int i = 0; i < len; i++) {
			int max1 = 1, max2 = 0;
			int j = 1;
			while (i - j >= 0 && i + j < len && s[i - j] == s[i + j]) {
				++j;
				max1 += 2;
			}
			if (max1 > maxi) {
				maxi = max1;
				ans = s.substr(i - j + 1, max1);
			}

			j = 0;
			while (i - j >= 0 && i + j + 1 < len && s[i - j] == s[i + j + 1]) {
				++j;
				max2 += 2;
			}
			if (max2 > maxi) {
				maxi = max2;
				ans = s.substr(i - j + 1, max2);
			}
		}
		return ans;
	}
};

int aa[] = { 1, 2 };
int bb[] = { 1, 1 };

int main() {
	Solution a;
	cout << a.longestPalindrome("abcdeedfggfd") << endl;
	return 0;
}
