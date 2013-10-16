//===============================================================================
//Median of Two Sorted Arrays
//There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//===============================================================================
class Solution {
public:
	double findMedianSortedArrays(int A[], int n, int B[], int m) {
		int cnt = (n + m) / 2, ii = 0, i = 0, j = 0, left, right;
		if (n == 0)
			return m % 2 == 0 ? 1.0f * (B[m / 2 - 1] + B[m / 2]) / 2 : B[m / 2];
		if (m == 0)
			return n % 2 == 0 ? 1.0f * (A[n / 2 - 1] + A[n / 2]) / 2 : A[n / 2];

		while (ii <= cnt) {
			right = left;
			if (i < n && j < m) {
				if (A[i] < B[j])
					left = A[i++];
				else
					left = B[j++];
			} else if (i < n) {
				left = A[i++];
			} else {
				left = B[j++];
			}
			++ii;
		}
		return (m + n) % 2 == 0 ? (left + right) * 1.0f / 2 : left;
	}
};
