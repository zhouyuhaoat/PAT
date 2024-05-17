/*
 *	author:		zhouyuhao
 *	created:	2023-04-06 11:12:00
 *	modified:	2023-04-06 11:33:03
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <queue>

using namespace std;

struct node {
	int v, r;
	node(int v, int r) : v(v), r(r) {
	}
	friend bool operator<(node a, node b) {
		if (a.r != b.r) {
			return a.r > b.r;
		} else {
			return a.v > b.v;
		}
	}
};

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	vector<vector<int>> run(n);
	priority_queue<node> q;
	for (int i = 0; i < m; i++) {
		q.emplace(d[i], 0);
	}
	for (int i = m; i < n; i++) {
		node t = q.top(); // t.v = lastin
		q.pop();
		run[t.r].emplace_back(t.v);
		if (d[i] > t.v) {
			q.emplace(d[i], t.r);
		} else {
			q.emplace(d[i], t.r + 1);
		}
	}
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		run[t.r].emplace_back(t.v);
	}
	for (int i = 0; i < n; i++) {
		if (run[i].empty()) {
			break;
		}
		for (int j = 0; j < (int)run[i].size(); j++) {
			cout << run[i][j];
			j < (int)run[i].size() - 1 ? cout << " " : cout << "\n";
		}
	}

	return 0;
}