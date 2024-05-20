/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 12:00:47
 *	modified:	2024-05-15 12:25:06
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1e4;

vector<vector<int>> g(maxn);
map<int, int> isfri;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int a = abs(stoi(s1)), b = abs(stoi(s2));
		if (s1.size() == s2.size()) {
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
		isfri[a * maxn + b] = isfri[b * maxn + a] = true;
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int s1, s2;
		cin >> s1 >> s2;
		int a = abs(s1), b = abs(s2);
		vector<pair<int, int>> ans;
		for (int i = 0; i < (int)g[a].size(); i++) {
			for (int j = 0; j < (int)g[b].size(); j++) {
				if (g[a][i] == b || a == g[b][j]) {
					continue;
				}
				if (isfri[g[a][i] * maxn + g[b][j]]) {
					ans.emplace_back(make_pair(g[a][i], g[b][j]));
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for (auto it : ans) {
			cout << setfill('0') << setw(4) << it.first << " " << setfill('0') << setw(4) << it.second << "\n";
		}
	}

	return 0;
}