/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 12:17:36
 *	modified:	2023-04-03 12:20:05
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
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
		vector<bool> edge(m, false);
		for (int i = 0; i < n; i++) {
			int v;
			cin >> v;
			for (auto it : e[v]) {
				edge[it] = true;
			}
		}
		bool flag = true;
		for (int i = 0; i < m; i++) {
			if (edge[i] == false) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}