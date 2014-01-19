#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:

	bool isOperator(string op) {
		if (op == "+" || op == "-" || op == "*" || op == "/") {
			return true;
		}
		return false;
	}

	long long toInt(string val) {
		long long result = 0;
		int sign = (val[0] == '-' ? -1 : 1);
		for (int i = sign == -1 ? 1 : 0; i < val.length(); i++) {
			result = result * 10 + (val[i] - '0');
		}
		return result * sign;
	}

	string toString(long long val) {
		char t[64];
		sprintf(t, "%lld", val);
		return t;
	}

	string calc(string op, string v1, string v2) {
		long long x1 = toInt(v1);
		long long x2 = toInt(v2);
		if (op == "+") {
			return toString(x1 + x2);
		}
		if (op == "-") {
			return toString(x1 - x2);
		}
		if (op == "*") {
			return toString(x1 * x2);
		}
		if (op == "/") {
			return toString(x1 / x2);
		}
		return "";
	}

	int evalRPN(vector<string> &tokens) {
		while (tokens.size() > 1) {
			vector<string> temp;
			for (int i = 0; i < tokens.size(); i++) {
				if (i > 1 && isOperator(tokens[i]) && !isOperator(tokens[i - 1]) && !isOperator(tokens[i - 2])) {
					temp.pop_back();
					temp.pop_back();
					string xx = calc(tokens[i], tokens[i - 2], tokens[i - 1]);
//					cout << i << "  " << xx << endl;
					temp.push_back(xx);
				} else {
					temp.push_back(tokens[i]);
				}
			}
			tokens = temp;
		}
		return toInt(tokens[0]);
	}
};

int main() {
	vector<string> test;
	test.push_back("4");
	test.push_back("-13");
	test.push_back("5");
	test.push_back("/");
	test.push_back("+");

	Solution aa;
	cout << aa.evalRPN(test) << endl;
	return 0;
}
