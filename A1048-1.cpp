/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 15:21:14
 *	modified:	2023-03-27 15:28:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	map<int, int> p;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		++p[d[i]];
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (p[m - d[i]] > 0 && !(d[i] == m / 2 && p[d[i]] == 1)) {
			s.emplace(d[i]);
		}
	}
	if (s.empty()) {
		cout << "No Solution\n";
	} else {
		cout << *s.begin() << " " << m - *s.begin() << "\n";
	}

	return 0;
}