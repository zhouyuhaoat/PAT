/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:45:05
 *	modified:	2023-04-13 17:52:56
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct per {
	string ent, exi;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].ent >> p[i].exi;
	}
	sort(p.begin(), p.end(), [](per a, per b) {
		if (a.exi != b.exi) {
			return a.exi < b.exi;
		} else {
			return a.ent < b.ent;
		}
	});
	int cnt = 1;
	string lastexi = p[0].exi;
	for (int i = 1; i < n; i++) {
		if (p[i].ent >= lastexi) {
			++cnt;
			lastexi = p[i].exi;
		}
	}
	cout << cnt << "\n";

	return 0;
}