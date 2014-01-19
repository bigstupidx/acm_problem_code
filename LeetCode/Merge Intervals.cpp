
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<pair<int, int> > arr;
		vector<Interval> ans;

		for (int i = 0, n = intervals.size(); i < n; i++) {
			Interval item = intervals[i];
			arr.push_back(make_pair(item.start, 0));
			arr.push_back(make_pair(item.end, 1));
		}

		sort(arr.begin(), arr.end());

		vector<pair<int, int> >::iterator p = arr.begin();

		stack<int> st;
		for (; p != arr.end(); p++) {
			if (p->second == 0) {
				st.push(p->first);
			} else {
				if (st.size() == 1) {
					Interval item(st.top(), p->first);
					ans.push_back(item);
				}
				st.pop();
			}
		}

//		for (; p != arr.end(); p++) {
//			printf("%d %d\n", p->first, p->second);
//		}

		return ans;
	}
};
