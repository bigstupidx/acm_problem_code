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

int n, arr[3] = {0, 1, 2}, xx[3];

bool solve(int total) {
    int temp = total*total;
    xx[0] = 1, xx[1] = total, xx[2] = total*total;
    for (int ii = 0; ii < 3; ii++) {
	for (int jj = 0; jj < 3; jj++) {
	    for (int kk = 0; kk < 3; kk++) {
		for (int i = 0; i < n; i++) {
		    nod[i].sum = nod[i].x * (temp / xx[ii]);
		    nod[i].sum += nod[i].y * (temp / xx[jj]);
		    nod[i].sum += nod[i].z * (temp / xx[kk]);
		    //printf("%d ", nod[i].sum);
		}
		//puts("");
		sort(nod, nod + n);
		if (strcmp(nod[0].str, "Canada") == 0)return true;
	    }
	}
    }
    return false;
}

int main() {
    while (scanf("%d", &n), n) {

	int xflag = 0, sum = 0;

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
