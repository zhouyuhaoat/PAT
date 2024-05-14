/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 22:17:15
 *	modified:	2023-04-02 22:20:30
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int lc, rc;
};

vector<bool> isroot;
vector<node> t;

int getid(string s) {
	if (isdigit(s[0])) {
		isroot[stoi(s)] = false;
		return stoi(s);
	} else {
		return -1;
	}
}

int maxid = -1, lastnode = -1;
void dfs(int r, int id) {
	if (r == -1) {
		return;
	}
	if (id > maxid) {
		maxid = id;
		lastnode = r;
	}
	dfs(t[r].lc, 2 * id + 1);
	dfs(t[r].rc, 2 * id + 2);
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	t.resize(n), isroot.resize(n, true);
	for (int i = 0; i < n; i++) {
		string lc, rc;
		cin >> lc >> rc;
		t[i] = {getid(lc), getid(rc)};
	}
	int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
	dfs(r, 0);
	if (maxid >= n) {
		cout << "NO " << r << "\n";
	} else {
		cout << "YES " << lastnode << "\n";
	}

	return 0;
}