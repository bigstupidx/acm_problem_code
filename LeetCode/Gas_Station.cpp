class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int sum = 0, n = gas.size(), m = n * 2, len = 0;
		for (int i = 0, j; i < m; i++) {
			j = i % n;
			sum += gas[j] - cost[j];
			if (sum < 0) {
				sum = 0;
				len = 0;
			} else {
				++len;
				if (len >= n) {
//					cout << i << endl;
					return (i - len + 1) % n;
				}
			}
		}
		return -1;
	}
};
