/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 10:25:11
 *	modified:	2023-03-28 11:39:51
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

struct node {
	char data;
	int next;
};

int main(int argc, char const *argv[]) {

	int front1, front2, n;
	cin >> front1 >> front2 >> n;
	if (front1 == -1 || front2 == -1) {
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
	int l1 = 0, l2 = 0;
	int id1 = front1, id2 = front2;
	do {
		++l1;
		id1 = d[loc[id1]].next;
	} while (id1 != -1);
	do {
		++l2;
		id2 = d[loc[id2]].next;
	} while (id2 != -1);
	id1 = front1, id2 = front2;
	if (l1 > l2) {
		for (int i = 0; i < l1 - l2; i++) {
			id1 = d[loc[id1]].next;
		}
	} else {
		for (int i = 0; i < l2 - l1; i++) {
			id2 = d[loc[id2]].next;
		}
	}
	int same = -1;
	do {
		if (id1 == id2) {
			same = id1;
			break;
		}
		id1 = d[loc[id1]].next;
		id2 = d[loc[id2]].next;
	} while (id1 != -1 && id2 != -1);
	if (same == -1) {
		cout << "-1\n";
	} else {
		cout << setfill('0') << setw(5) << same << "\n";
	}

	return 0;
}