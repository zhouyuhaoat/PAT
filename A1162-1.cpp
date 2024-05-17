/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:51:52
 *	modified:	2023-04-05 20:10:36
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	string v;
	int lc, rc;
};

vector<node> d;

void dfs(int r) {
	if (d[r].lc != -1 && d[r].rc != -1) {
		cout << "(";
		dfs(d[r].lc);
		dfs(d[r].rc);
		cout << d[r].v << ")";
		return;
	} else if (d[r].lc != -1 && d[r].rc == -1) {
		cout << "(";
		dfs(d[r].lc);
		cout << d[r].v << ")";
		return;
	} else if (d[r].lc == -1 && d[r].rc != -1) {
		cout << "(" << d[r].v;
		dfs(d[r].rc);
		cout << ")";
		return;
	} else {
		cout << "(" << d[r].v << ")";
		return;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	d.resize(n + 1);
	vector<bool> isroot(n + 1, true);
	for (int i = 1; i <= n; i++) {
		cin >> d[i].v >> d[i].lc >> d[i].rc;
		if (d[i].lc != -1) {
			isroot[d[i].lc] = false;
		}
		if (d[i].rc != -1) {
			isroot[d[i].rc] = false;
		}
	}
	int r = find(isroot.begin() + 1, isroot.end(), true) - isroot.begin();
	dfs(r);
	cout << "\n";

	return 0;
}