/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 12:29:53
 *	modified:	2023-03-29 14:40:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
double p, r, ms = -1;
vector<vector<int>> t;

void dfs(int rr, int l) {
	if (t[rr].empty()) {
		double s = p * pow(r, l);
		if (s > ms) {
			ms = s;
			cnt = 1;
		} else if (s == ms) {
			++cnt;
		}
		return;
	}
	for (int i = 0; i < (int)t[rr].size(); i++) {
		dfs(t[rr][i], l + 1);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n >> p >> r;
	r = r / 100 + 1;
	t.resize(n);
	int rr = -1;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == -1) {
			rr = i;
		} else {
			t[k].emplace_back(i);
		}
	}
	dfs(rr, 0);
	cout << fixed << setprecision(2) << ms << " " << cnt << "\n";

	return 0;
}