/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 22:49:25
 *	modified:	2023-04-05 23:05:37
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int addr, data, next;
};

vector<node> d(1e5);

int main(int argc, char const *argv[]) {

	int fn, n, k;
	cin >> fn >> n >> k;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id >> d[id].data >> d[id].next;
		d[id].addr = id;
	}
	vector<node> dd;
	do {
		dd.emplace_back(d[fn]);
		fn = d[fn].next;
	} while (fn != -1);
	vector<node> ans;
	for (int i = dd.size() - dd.size() % k; i < (int)dd.size(); i++) {
		ans.emplace_back(dd[i]);
	}
	int g = dd.size() / k;
	for (int i = g - 1; i >= 0; i--) {
		for (int j = i * k; j < (i + 1) * k; j++) {
			ans.emplace_back(dd[j]);
		}
	}
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << setfill('0') << setw(5) << ans[i].addr << " " << ans[i].data << " ";
		if (i < (int)ans.size() - 1) {
			cout << setfill('0') << setw(5) << ans[i + 1].addr << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}