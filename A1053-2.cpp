/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 16:09:30
 *	modified:	2023-03-29 16:47:59
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

void dfs(int r, int sum) {
	if (sum > s) {
		return;
	}
	if (sum == s) {
		if (!t[r].empty()) {
			return;
		}
		ans.emplace_back(temp);
		return;
	}
	for (int i = 0; i < (int)t[r].size(); i++) {
		temp.emplace_back(w[t[r][i]]);
		dfs(t[r][i], sum + w[t[r][i]]);
		temp.pop_back();
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
	temp.emplace_back(w[r]);
	dfs(r, w[r]);
	sort(ans.begin(), ans.end(), greater<vector<int>>());
	for (auto it : ans) {
		for (int i = 0; i < (int)it.size(); i++) {
			cout << it[i];
			i < (int)it.size() - 1 ? cout << " " : cout << "\n";
		}
	}

	return 0;
}