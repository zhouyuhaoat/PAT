/*
 *	author:		zhouyuhao
 *	created:	2024-05-16 21:30:52
 *	modified:	2024-05-16 21:40:03
 *	item:		Programming Ability Test
 *	site:		226, Harbin
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
	cout << "(";
	if (d[r].lc * d[r].rc > 1) {
		dfs(d[r].lc);
		dfs(d[r].rc);
	}
	cout << d[r].v;
	if (d[r].lc * d[r].rc < 0) {
		dfs(d[r].rc);
	}
	cout << ")";
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