/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 12:04:27
 *	modified:	2023-04-03 12:17:29
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].emplace_back(i);
		e[b].emplace_back(i);
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int n;
		cin >> n;
		set<int> edge;
		for (int i = 0; i < n; i++) {
			int v;
			cin >> v;
			for (auto it : e[v]) {
				edge.emplace(it);
			}
		}
		if ((int)edge.size() == m) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}