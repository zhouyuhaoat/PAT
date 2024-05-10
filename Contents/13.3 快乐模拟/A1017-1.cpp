/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 21:59:05
 *	modified:	2023-04-12 23:42:02
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct cus {
	int t, p;
	cus(int t, int p) : t(t), p(p) {
	}
	friend bool operator<(cus a, cus b) {
		return a.t > b.t;
	}
};

int trans(int h, int m, int s) {
	return h * 60 * 60 + m * 60 + s;
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	priority_queue<cus> c;
	int be = trans(8, 0, 0), en = trans(17, 0, 0);
	for (int i = 0; i < n; i++) {
		int h, m, s, p;
		int unused __attribute__((unused)) = 0;
		unused = scanf("%d:%d:%d %d", &h, &m, &s, &p);
		if (trans(h, m, s) > en) {
			continue;
		}
		c.emplace(trans(h, m, s), p * 60);
	}
	n = c.size();
	int wait = 0;
	priority_queue<int, vector<int>, greater<int>> w;
	for (int i = 0; i < k; i++) {
		if (!c.empty()) {
			cus ct = c.top();
			c.pop();
			if (ct.t < be) {
				wait += be - ct.t;
				ct.t = be;
			}
			w.emplace(ct.t + ct.p);
		} else {
			break;
		}
	}
	while (!c.empty()) {
		cus ct = c.top();
		c.pop();
		int wt = w.top();
		w.pop();
		if (ct.t < wt) {
			wait += wt - ct.t;
			w.emplace(wt + ct.p);
		} else {
			w.emplace(ct.t + ct.p);
		}
	}
	cout << fixed << setprecision(1) << (double)wait / n / 60 << "\n";

	return 0;
}