/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 11:45:35
 *	modified:	2023-03-28 11:45:41
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	char data;
	int next;
};

int main(int argc, char const *argv[]) {

	int n, id[2];
	cin >> id[0] >> id[1] >> n;
	if (id[0] == -1 || id[1] == -1) {
		cout << "-1\n";
		return 0;
	}
	node d[n + 1];
	map<int, int> loc;
	for (int i = 1; i <= n; i++) {
		int id;
		cin >> id >> d[i].data >> d[i].next;
		loc[id] = i;
	}
	vector<vector<int>> l(2);
	for (int i = 0; i < 2; i++) {
		do {
			l[i].emplace_back(id[i]);
			id[i] = d[loc[id[i]]].next;
		} while (id[i] != -1);
		reverse(l[i].begin(), l[i].end());
	}
	int same = -1;
	for (int i = 0; i < (int)l[0].size() && i < (int)l[1].size(); i++) {
		if (l[0][i] == l[1][i]) {
			same = l[0][i];
		} else {
			break;
		}
	}
	if (same == -1) {
		cout << "-1\n";
	} else {
		cout << setfill('0') << setw(5) << same << "\n";
	}

	return 0;
}