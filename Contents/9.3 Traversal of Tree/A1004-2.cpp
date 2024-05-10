/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 15:00:01
 *	modified:	2023-03-29 15:12:48
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int hh = -1;
vector<int> h;
map<int, int> cnt;
vector<vector<int>> t;

void bfs(int r) {
	queue<int> q;
	q.emplace(r);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		hh = max(hh, h[f]);
		if (t[f].empty()) {
			++cnt[h[f]];
		}
		for (int i = 0; i < (int)t[f].size(); i++) {
			h[t[f][i]] = h[f] + 1;
			q.emplace(t[f][i]);
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	t.resize(n + 1);
	vector<bool> isroot(n + 1, true);
	for (int i = 0; i < m; i++) {
		int id, k;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			int c;
			cin >> c;
			t[id].emplace_back(c);
			isroot[c] = false;
		}
	}
	int r = find(isroot.begin(), isroot.end(), true) - isroot.begin() + 1;
	h.resize(n);
	h[r] = 1;
	bfs(r);
	for (int i = 1; i <= hh; i++) {
		cout << cnt[i];
		i <= hh - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}