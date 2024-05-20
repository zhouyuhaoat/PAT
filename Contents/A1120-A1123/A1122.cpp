/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:12:38
 *	modified:	2023-04-03 02:25:25
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> g;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	g.resize(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1][v2] = g[v2][v1] = 1;
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int nn;
		cin >> nn;
		vector<int> p(nn);
		set<int> v;
		for (int i = 0; i < nn; i++) {
			cin >> p[i];
			v.emplace(p[i]);
		}
		if ((int)v.size() != n) {
			cout << "NO\n";
			continue;
		}
		bool isarr = true;
		set<int> spp;
		for (int i = 1; i < nn; i++) {
			spp.emplace(p[i]);
			if (g[p[i - 1]][p[i]] != 1) {
				isarr = false;
				break;
			}
		}
		if (!isarr || (int)spp.size() != nn - 1) {
			cout << "NO\n";
			continue;
		}
		if (p[0] != p[nn - 1]) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}

	return 0;
}