#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    char str[102];
    int x, y, z, sum, level;

    bool operator<(const node & a)const {
	if (a.sum == sum)return a.level > level;
	return a.sum < sum;
    }
} nod[22];

int n, arr[3] = {0, 1, 2}, pow[3];

bool solve(int total) {
    pow[0] = 1;
    pow[1] = total;
    pow[2] = total*total;
    for (int ii = 0; ii < 3; ii++) {
	for (int jj = 0; jj < 3; jj++) {
	    for (int kk = 0; kk < 3; kk++) {
		for (int i = 0; i < n; i++) {
		    nod[i].sum = nod[i].x * pow[ii];
		    nod[i].sum += nod[i].y * pow[jj];
		    nod[i].sum += nod[i].z * pow[kk];
		}
		sort(nod, nod + n);
		if (strcmp(nod[0].str, "Canada") == 0)return true;
	    }
	}
    }
    return false;
}

int main() {
    while (scanf("%d", &n), n) {
	int sum = 0, xflag = 0;
	for (int i = 0; i < n; i++) {
	    scanf("%s%d%d%d", nod[i].str, &nod[i].x, &nod[i].y, &nod[i].z);
	    if (strcmp(nod[i].str, "Canada") == 0) {
		xflag = 1;
		nod[i].level = 0;
	    } else nod[i].level = 1;
	    sum += nod[i].x + nod[i].y + nod[i].z;
	}
	if (!xflag) {
	    puts("Canada cannot win.");
	    continue;
	}
	if (solve(sum))puts("Canada wins!");
	else puts("Canada cannot win.");
    }
    return 0;
}

