/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 15:08:53
 *	modified:	2023-04-04 15:22:27
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> ind(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].emplace_back(b);
		++ind[b];
	}
	int k;
	cin >> k;
	vector<int> ans;
	for (int q = 0; q < k; q++) {
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		vector<int> indtemp(ind);
		for (int i = 0; i < n; i++) {
			if (indtemp[d[i]] == 0) {
				for (auto it : g[d[i]]) {
					--indtemp[it];
				}
			} else {
				ans.emplace_back(q);
				break;
			}
		}
	}
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i];
		i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
	}

	return 0;
}