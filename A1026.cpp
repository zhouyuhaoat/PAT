/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 08:51:27
 *	modified:	2023-04-14 10:12:40
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct per {
	int at, pt, st;
	bool isvip;
};

int trans(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
int be = trans(8, 0, 0), en = trans(21, 0, 0);

struct tab {
	int cnt, et = be;
	bool isvip;
};

void print(int t) {
	cout << setfill('0') << setw(2) << t / 60 / 60 << ":";
	cout << setfill('0') << setw(2) << t / 60 % 60 << ":";
	cout << setfill('0') << setw(2) << t % 60 << " ";
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		int h, m, s, pt, f;
		cin >> h, getchar();
		cin >> m, getchar();
		cin >> s >> pt >> f;
		p[i].at = trans(h, m, s);
		if (pt > 120) {
			pt = 120;
		}
		p[i].pt = pt * 60;
		if (f) {
			p[i].isvip = true;
		}
	}
	sort(p.begin(), p.end(), [](per a, per b) -> bool {
		return a.at < b.at;
	});
	int k, m;
	cin >> k >> m;
	vector<tab> t(k);
	vector<int> tv(m);
	for (int i = 0; i < m; i++) {
		cin >> tv[i];
		t[--tv[i]].isvip = true;
	}
	vector<bool> vis(n);
	int pi = 0;
	while (pi < n) {
		if (vis[pi]) {
			++pi;
			continue;
		}
		if (p[pi].isvip) {
			int ti = -1;
			for (int i = 0; i < m; i++) {
				if (p[pi].at >= t[tv[i]].et) {
					ti = i;
					break;
				}
			}
			if (ti != -1) {
				p[pi].st = p[pi].at;
				t[tv[ti]].et = p[pi].st + p[pi].pt;
				if (p[pi].st < en) {
					++t[tv[ti]].cnt;
				}
				vis[pi] = true;
				++pi;
				continue;
			}
		}
		int ti = -1;
		for (int i = 0; i < k; i++) {
			if (p[pi].at >= t[i].et) {
				ti = i;
				break;
			}
		}
		if (ti != -1) {
			p[pi].st = p[pi].at;
			t[ti].et = p[pi].st + p[pi].pt;
			if (p[pi].st < en) {
				++t[ti].cnt;
			}
			vis[pi] = true;
			++pi;
		} else {
			int minti = -1, minet = INT_MAX;
			for (int i = 0; i < k; i++) {
				if (t[i].et < minet) {
					minet = t[i].et;
					minti = i;
				}
			}
			if (!t[minti].isvip) {
				p[pi].st = t[minti].et;
				t[minti].et += p[pi].pt;
				if (p[pi].st < en) {
					++t[minti].cnt;
				}
				vis[pi] = true;
				++pi;
			} else {
				int tpi = pi;
				for (int i = tpi; i < n; i++) {
					if (!vis[i]) {
						if (p[i].at <= t[minti].et) {
							if (p[i].isvip) {
								pi = i;
								break;
							}
						} else {
							break;
						}
					}
				}
				p[pi].st = t[minti].et;
				t[minti].et += p[pi].pt;
				if (p[pi].st < en) {
					++t[minti].cnt;
				}
				vis[pi] = true;
				pi = tpi;
			}
		}
	}
	sort(p.begin(), p.end(), [](per a, per b) -> bool {
		return a.st < b.st;
	});
	for (auto it : p) {
		if (it.st >= en) {
			continue;
		}
		print(it.at), print(it.st);
		cout << (it.st - it.at + 30) / 60 << "\n";
	}
	for (int i = 0; i < k; i++) {
		cout << t[i].cnt;
		i < k - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}