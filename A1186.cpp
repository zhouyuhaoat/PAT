/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:24:13
 *	modified:	2023-04-13 20:48:04
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<set<int>> g;
vector<bool> vis;
vector<int> cnt;

void dfs(int n, int s) {
	vis[n] = true;
	++cnt[s];
	for (auto it : g[n]) {
		if (!vis[it]) {
			dfs(it, s);
			return;
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].emplace(v);
		g[v].emplace(u);
	}
	vis.resize(n + 1), cnt.resize(n + 1);
	int s = 1, maxl = -1;
	for (int i = 1; i <= n; i++) {
		fill(vis.begin(), vis.end(), false);
		dfs(i, i);
		if (cnt[i] > maxl) {
			maxl = cnt[i];
			s = i;
		}
	}
	cout << s << " " << maxl << "\n";

	return 0;
}