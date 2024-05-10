/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 13:10:27
 *	modified:	2023-03-29 14:53:22
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
double p, r, ls = INT_MAX;
vector<vector<int>> t;

void dfs(int rr, int l) {
	if (t[rr].empty()) {
		double s = p * pow(r, l);
		if (s < ls) {
			ls = s;
			cnt = 1;
		} else if (s == ls) {
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
	vector<bool> isroot(n, true);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int id;
			cin >> id;
			t[i].emplace_back(id);
			isroot[id] = false;
		}
	}
	int rr = find(isroot.begin(), isroot.end(), true) - isroot.begin();
	dfs(rr, 0);
	cout << fixed << setprecision(4) << ls << " " << cnt << "\n";

	return 0;
}