/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:20:40
 *	modified:	2023-04-13 17:44:58
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
		if (a.ent != b.ent) {
			return a.ent > b.ent;
		} else {
			return a.exi < b.exi;
		}
	});
	int cnt = 1;
	string lastent = p[0].ent;
	for (int i = 1; i < n; i++) {
		if (p[i].exi <= lastent) {
			++cnt;
			lastent = p[i].ent;
		}
	}
	cout << cnt << "\n";

	return 0;
}