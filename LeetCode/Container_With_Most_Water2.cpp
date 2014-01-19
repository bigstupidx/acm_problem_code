class Solution {
public:
	int maxArea(vector<int> &height) {
		int maxi = 0;
		for (int i = 0, n = height.size(); i < n; i++) {
			for (int j = n - 1; j > i; j--) {
				if ((j - i) * height[i] < maxi)
					break;
				int temp = (j - i) * min(height[i], height[j]);
				if (temp > maxi)
					maxi = temp;
			}
		}
		return maxi;
	}
};
