#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point() :
			x(0), y(0) {
	}
	Point(int a, int b) :
			x(a), y(b) {
	}
};

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int maxi = 0, size = points.size();

		if (size < 2)
			return size;

		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				Point aa = points[i];
				Point bb = points[j];

				int a = aa.x - bb.x;
				int b = aa.y - bb.y;

				int cnt = 2;

				for (int k = 0; k < size; k++) {
					if (k == i || k == j)
						continue;
					Point cc = points[k];
					if (cc.x == aa.x && cc.y == aa.y || cc.x == bb.x && cc.y == bb.y) {
						++cnt;
						continue;
					}
					if (a == 0 && b == 0) {
						continue;
					}
					int c = cc.x - bb.x;
					int d = cc.y - bb.y;

					if (a * d == c * b)
						++cnt;
				}
				if (cnt > maxi)
					maxi = cnt;
			}
		}

		return maxi;
	}
};

int main() {
	return 0;
}
