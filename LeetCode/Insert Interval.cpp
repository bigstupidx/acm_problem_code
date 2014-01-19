class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ans;
		bool flag = false;
		for (int i = 0, n = intervals.size(); i < n; i++) {
			Interval item = intervals[i];
			if (item.end < newInterval.start) {
				ans.push_back(item);
			} else if (item.start > newInterval.end) {
				if (!flag) {
					flag = true;
					ans.push_back(newInterval);
				}
				ans.push_back(item);
			} else {
				newInterval.start = min(newInterval.start, item.start);
				newInterval.end = max(newInterval.end, item.end);
			}
		}
		if (!flag)
			ans.push_back(newInterval);
		return ans;
	}
};
