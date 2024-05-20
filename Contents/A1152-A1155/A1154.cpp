/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 20:46:37
 *	modified:	2023-04-04 21:01:01
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
	vector<pair<int, int>> g;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g.emplace_back(a, b);
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		vector<int> c(n);
		set<int> color;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			color.emplace(c[i]);
		}
		bool isclr = true;
		for (auto it : g) {
			if (c[it.first] == c[it.second]) {
				isclr = false;
				break;
			}
		}
		if (isclr) {
			cout << color.size() << "-coloring\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}