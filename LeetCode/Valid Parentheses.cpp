#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			char ch = s[i];
			if (ch == '}' || ch == ')' || ch == ']') {
				if (st.size() == 0)
					return false;
				char bh = st.top();
				if ((bh == '(' && ch == ')') || (bh == '{' && ch == '}') || (bh == '[' && ch == ']')) {
					st.pop();
				} else {
					return false;
				}
			} else {
				st.push(ch);
			}
		}
		if (st.size() == 0)
			return true;
		return false;
	}
};

int main() {
	return 0;
}
