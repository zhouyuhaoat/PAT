/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:37:03
 *	modified:	2023-04-02 22:16:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int v, id;
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

void dfs(int r, int id) {
	t[r].id = id;
	if (t[r].lc != -1) {
		dfs(t[r].lc, 2 * id + 1);
	}
	if (t[r].rc != -1) {
		dfs(t[r].rc, 2 * id + 2);
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	t.resize(n), isroot.resize(n, true);
	for (int i = 0; i < n; i++) {
		string lc, rc;
		cin >> lc >> rc;
		t[i] = {i, 0, getid(lc), getid(rc)};
	}
	int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
	dfs(r, 0);
	sort(t.begin(), t.end(), [](node a, node b) {
		return a.id < b.id;
	});
	for (int i = 0; i < n; i++) {
		if (t[i].id != i) {
			cout << "NO " << r << "\n";
			return 0;
		}
	}
	cout << "YES " << t[n - 1].v << "\n";

	return 0;
}