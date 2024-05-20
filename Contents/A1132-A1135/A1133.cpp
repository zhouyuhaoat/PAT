/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 11:53:38
 *	modified:	2023-04-03 12:03:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int id, v, next;
};

vector<node> d(1e5);

int main(int argc, char const *argv[]) {

	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		d[id].id = id;
		cin >> d[id].v >> d[id].next;
	}
	vector<node> a1, a2, a3;
	do {
		if (d[head].v < 0) {
			a1.emplace_back(d[head]);
		} else if (d[head].v <= k) {
			a2.emplace_back(d[head]);
		} else {
			a3.emplace_back(d[head]);
		}
		head = d[head].next;
	} while (head != -1);
	vector<node> ans(a1);
	ans.insert(ans.end(), a2.begin(), a2.end());
	ans.insert(ans.end(), a3.begin(), a3.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << setfill('0') << setw(5) << ans[i].id << " " << ans[i].v << " ";
		if (i < (int)ans.size() - 1) {
			cout << setfill('0') << setw(5) << ans[i + 1].id << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}