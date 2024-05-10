/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 12:03:48
 *	modified:	2023-03-28 12:05:47
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
	int id, data, next;
};

int main(int argc, char const *argv[]) {

	int n, id;
	cin >> n >> id;
	if (id == -1) {
		cout << "0 -1\n";
		return 0;
	}
	node d[n + 1];
	map<int, int> loc;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].id >> d[i].data >> d[i].next;
		loc[d[i].id] = i;
	}
	vector<node> l;
	do {
		l.emplace_back(d[loc[id]]);
		id = d[loc[id]].next;
	} while (id != -1);
	sort(l.begin(), l.end(), [](node a, node b) -> bool {
		return a.data < b.data;
	});
	cout << l.size() << " " << setfill('0') << setw(5) << l[0].id << "\n";
	for (int i = 0; i < (int)l.size(); i++) {
		cout << setfill('0') << setw(5) << l[i].id << " " << l[i].data << " ";
		if (i < (int)l.size() - 1) {
			cout << setfill('0') << setw(5) << l[i + 1].id << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}