/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 12:45:43
 *	modified:	2023-03-29 14:49:47
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> cnt;
vector<vector<int>> t;

void dfs(int r, int l) {
	++cnt[l];
	for (int i = 0; i < (int)t[r].size(); i++) {
		dfs(t[r][i], l + 1);
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
	dfs(r, 1);
	vector<pair<int, int>> ans(cnt.begin(), cnt.end());
	sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
		return a.second > b.second;
	});
	cout << ans[0].second << " " << ans[0].first << "\n";

	return 0;
}