/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 14:15:03
 *	modified:	2023-04-04 14:22:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> pre;
map<int, bool> exist;

int main(int argc, char const *argv[]) {

	int m, n;
	cin >> m >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
		exist[pre[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (exist[u] && exist[v]) {
			int a = u, b = v;
			if (a > b) {
				swap(a, b);
			}
			int lca = -1;
			for (int j = 0; j < n; j++) {
				if (pre[j] > a && pre[j] <= b) {
					lca = pre[j];
					break;
				} else if (pre[j] == a && pre[j] <= b) {
					lca = pre[j];
					break;
				}
			}
			if (lca != u && lca != v) {
				cout << "LCA of " << u << " and " << v << " is " << lca << ".\n";
			} else if (lca == u && lca != v) {
				cout << u << " is an ancestor of " << v << ".\n";
			} else {
				cout << v << " is an ancestor of " << u << ".\n";
			}
		} else if (exist[u] && !exist[v]) {
			cout << "ERROR: " << v << " is not found.\n";
		} else if (!exist[u] && exist[v]) {
			cout << "ERROR: " << u << " is not found.\n";
		} else {
			cout << "ERROR: " << u << " and " << v << " are not found.\n";
		}
	}

	return 0;
}