/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 15:47:21
 *	modified:	2024-05-15 15:58:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	map<int, vector<int>> dan;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dan[a].emplace_back(b);
		dan[b].emplace_back(a);
	}
	for (int q = 0; q < m; q++) {
		int k;
		cin >> k;
		vector<int> goods(k);
		map<int, bool> exist;
		for (int i = 0; i < k; i++) {
			cin >> goods[i];
			exist[goods[i]] = true;
		}
		bool issafe = true;
		for (int i = 0; i < k && issafe; i++) {
			for (int j = 0; j < (int)dan[goods[i]].size() && issafe; j++) {
				if (exist[dan[goods[i]][j]]) {
					issafe = false;
				}
			}
		}
		if (issafe) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}