/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 12:57:25
 *	modified:	2023-04-04 13:13:03
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ins {
	int r, t, n;
	string id;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	map<string, double> inss;
	map<string, int> insc;
	for (int i = 0; i < n; i++) {
		string id, sch;
		int sco;
		cin >> id >> sco >> sch;
		for (int j = 0; j < (int)sch.size(); j++) {
			sch[j] = tolower(sch[j]);
		}
		if (id[0] == 'T') {
			inss[sch] += sco * 1.5;
		} else if (id[0] == 'B') {
			inss[sch] += sco / 1.5;
		} else {
			inss[sch] += sco;
		}
		++insc[sch];
	}
	vector<ins> ans;
	for (auto it : inss) {
		ans.emplace_back(ins{1, (int)it.second, insc[it.first], it.first});
	}
	sort(ans.begin(), ans.end(), [](ins a, ins b) {
		if (a.t != b.t) {
			return a.t > b.t;
		} else if (a.n != b.n) {
			return a.n < b.n;
		} else {
			return a.id < b.id;
		}
	});
	cout << ans.size() << "\n";
	cout << ans[0].r << " " << ans[0].id << " " << ans[0].t << " " << ans[0].n << "\n";
	for (int i = 1; i < (int)ans.size(); i++) {
		if (ans[i].t == ans[i - 1].t) {
			ans[i].r = ans[i - 1].r;
		} else {
			ans[i].r = i + 1;
		}
		cout << ans[i].r << " " << ans[i].id << " " << ans[i].t << " " << ans[i].n << "\n";
	}

	return 0;
}