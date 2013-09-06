#include <iostream>
#include <cstring>
#include <cstdio>
#define clr(a) memset(a,0,sizeof(a));

using namespace std;

struct myset {
	int s[4];

	inline void clear() {
		s[0] = s[1] = s[2] = s[3] = 0;
	}

	inline bool inside(int i) const {
		return s[i / 32]&(1 << (i % 32));
	}

	inline void add(int i) {
		s[i / 32] |= ((1) << (i % 32));
	}
};

bool operator ==(const myset& a, const myset& b) {
	return a.s[0] == b.s[0] && a.s[1] == b.s[1] && a.s[2] == b.s[2] && a.s[3] == b.s[3];
}

myset operator &(const myset& a, const myset& b) {
	myset c;
	c.s[0] = a.s[0] & b.s[0];
	c.s[1] = a.s[1] & b.s[1];
	c.s[2] = a.s[2] & b.s[2];
	c.s[3] = a.s[3] & b.s[3];
	return c;
}

struct hashnode {
	myset s;
	hashnode *next, *pre;
};
const int hashsize = 3007, maxhash = 20007;

class hash {
private:
	hashnode mem[maxhash];
	int mem_end;
	hashnode h[maxhash];
	int tnow, tag[maxhash];

	inline int culhash(const myset& s) {
		return (s.s[0]^s.s[1]^s.s[2]^s.s[3]) % maxhash;
	}

	inline hashnode* getmem() {
		mem_end++;
		return mem + mem_end;
	}
public:

	hash() {
		clr(tag);
		tnow = 1;
	}

	void reset() {
		mem_end = 0;
		tnow++;
	}

	bool inside(const myset& s) {
		int i = culhash(s);
		if (tag[i] == tnow) {
			hashnode *p = h[i].next;
			while (p) {
				if (p->s == s) return true;
				p = p->next;
			}
		}
		return false;
	}

	void insert(const myset& s) {
		int i = culhash(s);
		hashnode *p = getmem();
		p->s = s;
		if (tag[i] == tnow) {
			p->next = h[i].next;
			if (p->next) p->next->pre = p;
			p->pre = h + i;
			h[i].next = p;
		}
		else {
			p->next = 0;
			p->pre = h + i;
			h[i].next = p;
			tag[i] = tnow;
		}
	}

	void remove(const myset& s) {
		int i = culhash(s);
		hashnode *p = h[i].next;
		while (p) {
			if (p->s == s) {
				p->pre->next = p->next;
				if (p->next)
					p->next->pre = p->pre;
				return;
			}
			p = p->next;
		}
	}
} hhh;

myset lin[130], pick[1200];

bool ok(const myset& s, int k) {
	for (int i = 0; i < k; i++) {
		if (!s.inside(i) && s == (s & lin[i]))
			return false;
	}
	return true;
}

int solve(int n) {
	myset s;
	pick[0].clear();
	pick[0].add(0);
	hhh.reset();
	hhh.insert(pick[0]);
	int now = 1, ans = 1;
	for (int k = 1; k < n && ans <= 1000; k++, now = ans) {
		for (int j = 0; j < now && ans <= 1000; j++) {
			s = pick[j] & lin[k];
			if (s == pick[j]) {
				hhh.remove(pick[j]);
				pick[j].add(k);
				hhh.insert(pick[j]);
			}
			else {
				s.add(k);
				if (!hhh.inside(s) && ok(s, k)) {
					hhh.insert(s);
					pick[ans] = s;
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			lin[i].clear();
		}
		for (int a, b, i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			a--;
			b--;
			lin[a].add(b);
			lin[b].add(a);
		}
		int k = solve(n);
		if (k <= 1000)
			cout << k << endl;
		else puts("Too many maximal sets of friends.");
	}
	return 0;
}
