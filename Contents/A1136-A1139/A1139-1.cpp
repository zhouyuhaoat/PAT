/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 13:30:11
 *	modified:	2023-04-04 12:25:47
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1e4 + 1;

struct fri {
	int il, ir;
};

vector<vector<int>> g(maxn);
map<int, int> isfri;
map<int, char> gender;
vector<fri> ans;

bool isfzero(string s) {
	if (s[0] == '-' && stoi(s) == 0) {
		return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int a = stoi(s1), b = stoi(s2);
		a >= 0 ? gender[a] = 'M' : gender[abs(a)] = 'F';
		b >= 0 ? gender[b] = 'M' : gender[abs(b)] = 'F';
		if (isfzero(s1)) {
			a += maxn - 1;
			gender[a] = 'F';
		}
		if (isfzero(s2)) {
			b += maxn - 1;
			gender[b] = 'F';
		}
		a = abs(a), b = abs(b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		isfri[a * maxn + b] = true;
		isfri[b * maxn + a] = true;
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		string s1, s2;
		cin >> s1 >> s2;
		int a = stoi(s1), b = stoi(s2);
		if (isfzero(s1)) {
			a += maxn - 1;
		}
		if (isfzero(s2)) {
			b += maxn - 1;
		}
		a = abs(a), b = abs(b);
		for (int i = 0; i < (int)g[a].size(); i++) {
			int u = g[a][i];
			if (gender[u] == gender[a]) {
				for (int j = 0; j < (int)g[u].size(); j++) {
					int v = g[u][j];
					if (gender[a] != gender[b]) {
						if (gender[v] != gender[u]) {
							if (isfri[v * maxn + b]) {
								if (u != a && u != b && v != a && v != b) {
									ans.emplace_back(fri{u, v});
								}
							}
						}
					} else {
						if (gender[v] == gender[u]) {
							if (isfri[v * maxn + b]) {
								if (u != a && u != b && v != a && v != b) {
									ans.emplace_back(fri{u, v});
								}
							}
						}
					}
				}
			}
		}
		sort(ans.begin(), ans.end(), [](fri a, fri b) {
			if (a.il != b.il) {
				return a.il < b.il;
			} else {
				return a.ir < b.ir;
			}
		});
		cout << ans.size() << "\n";
		for (auto it : ans) {
			if (it.il == maxn - 1) {
				it.il = 0;
			}
			if (it.ir == maxn - 1) {
				it.ir = 0;
			}
			cout << setfill('0') << setw(4) << it.il << " " << setfill('0') << setw(4) << it.ir << "\n";
		}
		ans.clear();
	}

	return 0;
}