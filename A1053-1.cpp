/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 13:18:41
 *	modified:	2023-03-29 16:43:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int s;
vector<int> w, temp;
vector<vector<int>> t, ans;

void dfs(int r, int sum, int l) {
	temp.resize(l + 1);
	temp[l] = w[r];
	sum += w[r];
	if (t[r].empty()) {
		if (sum == s) {
			ans.emplace_back(temp);
		}
		return;
	}
	if (sum > s) {
		return;
	}
	for (int i = 0; i < (int)t[r].size(); i++) {
		dfs(t[r][i], sum, l + 1);
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m >> s;
	w.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	t.resize(n);
	vector<bool> isroot(n, true);
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
	int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
	dfs(r, 0, 0);
	sort(ans.begin(), ans.end(), greater<vector<int>>());
	for (auto it : ans) {
		for (int i = 0; i < (int)it.size(); i++) {
			cout << it[i];
			i < (int)it.size() - 1 ? cout << " " : cout << "\n";
		}
	}

	return 0;
}