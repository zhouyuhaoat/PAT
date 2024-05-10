/*
 *	author:		zhouyuhao
 *	created:	2024-05-08 19:50:05
 *	modified:	2024-05-08 19:59:02
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct cus {
	string t;
	int p;
	cus(string t, int p) : t(t), p(p) {
	}
	friend bool operator<(cus a, cus b) {
		return a.t > b.t;
	}
};

int trans(string t) {
	int h = stoi(t.substr(0, 2));
	int m = stoi(t.substr(3, 2));
	int s = stoi(t.substr(6, 2));
	return h * 3600 + m * 60 + s;
}

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	priority_queue<cus> c;
	string be = "08:00:00", en = "17:00:00";
	for (int i = 0; i < n; i++) {
		string t;
		int p;
		cin >> t >> p;
		if (t > en) {
			continue;
		}
		c.emplace(t, p * 60);
	}
	n = c.size();
	int wait = 0;
	priority_queue<int, vector<int>, greater<int>> w;
	for (int i = 0; i < k; i++) {
		if (!c.empty()) {
			cus ct = c.top();
			c.pop();
			if (ct.t < be) {
				wait += trans(be) - trans(ct.t);
				ct.t = be;
			}
			w.emplace(trans(ct.t) + ct.p);
		} else {
			break;
		}
	}
	while (!c.empty()) {
		cus ct = c.top();
		c.pop();
		int wt = w.top();
		w.pop();
		int ctt = trans(ct.t);
		if (ctt < wt) {
			wait += wt - ctt;
			w.emplace(wt + ct.p);
		} else {
			w.emplace(ctt + ct.p);
		}
	}
	cout << fixed << setprecision(1) << (double)wait / n / 60 << "\n";

	return 0;
}