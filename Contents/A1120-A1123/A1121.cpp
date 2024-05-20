/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 01:56:12
 *	modified:	2023-04-03 02:12:12
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<int, int> c;
	for (int i = 0; i < n; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		c[c1] = c2, c[c2] = c1;
	}
	int m;
	cin >> m;
	map<int, bool> g;
	vector<int> d(m);
	for (int i = 0; i < m; i++) {
		cin >> d[i];
		g[d[i]] = true;
	}
	set<int> single;
	for (int i = 0; i < m; i++) {
		if (!g[c[d[i]]]) {
			single.emplace(d[i]);
		}
	}
	int size = single.size();
	cout << size << "\n";
	for (auto it : single) {
		cout << setfill('0') << setw(5) << it;
		--size > 0 ? cout << " " : cout << "\n";
	}

	return 0;
}