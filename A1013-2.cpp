/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 13:32:42
 *	modified:	2023-03-30 13:45:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<bool> vis;
vector<int> f;
vector<vector<int>> g;

int find(int x) {
	int a = x;
	while (x != f[x]) {
		x = f[x];
	}
	while (a != f[a]) {
		int z = a;
		a = f[a], f[z] = x;
	}
	return x;
}

void joint(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa != fb) {
		f[fa] = fb;
	}
}

int main(int argc, char const *argv[]) {

	int n, m, k;
	cin >> n >> m >> k;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		g[s].emplace_back(e);
		g[e].emplace_back(s);
	}
	f.resize(n + 1), vis.resize(n + 1);
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		iota(f.begin(), f.end(), 0);
		fill(vis.begin(), vis.end(), false);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (int)g[i].size(); j++) {
				int u = i, v = g[i][j];
				if (u != id && v != id) {
					joint(u, v);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int fi = find(i);
			if (i != id && !vis[fi]) {
				++cnt;
				vis[fi] = true;
			}
		}
		cout << cnt - 1 << "\n";
	}

	return 0;
}