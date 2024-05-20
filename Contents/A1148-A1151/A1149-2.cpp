/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 16:12:21
 *	modified:	2024-05-15 16:35:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1e5;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	map<int, bool> dan, isdan;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dan[a * maxn + b] = dan[b * maxn + a] = true;
		isdan[a] = isdan[b] = true;
	}
	for (int q = 0; q < m; q++) {
		int k;
		cin >> k;
		vector<int> goods;
		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			if (isdan[a]) {
				goods.emplace_back(a);
			}
		}
		bool issafe = true;
		for (int i = 0; i < (int)goods.size() - 1 && issafe; i++) {
			for (int j = i + 1; j < (int)goods.size() && issafe; j++) {
				if (dan[goods[i] * maxn + goods[j]]) {
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