class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int size = digits.size();
		if (size == 0) {
			digits.push_back(1);
		} else {
			digits[size - 1] += 1;
			int i = size - 1;
			int carry = 0;
			while (i >= 0 && (carry != 0 || digits[i] >= 10)) {
				digits[i] += carry;
				carry = digits[i] / 10;
				digits[i] %= 10;
				--i;
			}
			if (carry != 0) {
				digits.push_back(0);
				for (int i = size; i > 0; i--) {
					digits[i] = digits[i - 1];
				}
				digits[0] = carry;
			}
		}
		return digits;
	}
};
