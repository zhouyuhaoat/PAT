/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:13:36
 *	modified:	2023-04-13 20:24:06
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct per {
	int id, w;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].w;
		p[i].id = i;
	}
	vector<int> s(d);
	sort(s.begin(), s.end(), greater<int>());
	map<int, int> order;
	for (int i = 0; i < n; i++) {
		order[s[i]] = i;
	}
	sort(p.begin(), p.end(), [](per a, per b) {
		return a.w > b.w;
	});
	for (int i = n - 1; i >= 0; i--) {
		cout << p[order[d[i]]].id + 1;
		i > 0 ? cout << " " : cout << "\n";
	}

	return 0;
}