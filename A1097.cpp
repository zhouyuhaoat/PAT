/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:54:59
 *	modified:	2023-03-28 12:10:27
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	int data, next;
};

int main(int argc, char const *argv[]) {

	int id, n;
	cin >> id >> n;
	node d[n + 1];
	map<int, int> loc, cnt;
	for (int i = 1; i <= n; i++) {
		int id;
		cin >> id >> d[i].data >> d[i].next;
		loc[id] = i;
		if (cnt[abs(d[i].data)] == 0) {
			cnt[abs(d[i].data)] = 1;
		}
	}
	vector<vector<int>> l(2);
	do {
		if (cnt[abs(d[loc[id]].data)] == 1) {
			l[0].emplace_back(id);
			cnt[abs(d[loc[id]].data)] = 0;
		} else {
			l[1].emplace_back(id);
		}
		id = d[loc[id]].next;
	} while (id != -1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < (int)l[i].size(); j++) {
			cout << setfill('0') << setw(5) << l[i][j] << " " << d[loc[l[i][j]]].data << " ";
			if (j < (int)l[i].size() - 1) {
				cout << setfill('0') << setw(5) << l[i][j + 1] << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}