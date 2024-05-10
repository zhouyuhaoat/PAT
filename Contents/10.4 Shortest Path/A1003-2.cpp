/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 19:07:00
 *	modified:	2023-03-30 19:30:26
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <climits>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

struct node {
	int v, d;
	node(int v, int d) : v(v), d(d) {
	}
	friend bool operator<(node a, node b) {
		return a.d > b.d;
	}
};

vector<bool> vis;
vector<int> d, t;
vector<vector<int>> pre;
vector<vector<node>> g;

void dijkstra(int s) {
	d[s] = 0;
	priority_queue<node> q;
	q.emplace(s, 0);
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		int u = t.v;
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < (int)g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (d[u] + g[u][i].d < d[v]) {
					d[v] = d[u] + g[u][i].d;
					pre[v].clear();
					pre[v].emplace_back(u);
					q.emplace(v, d[v]);
				} else if (d[u] + g[u][i].d == d[v]) {
					pre[v].emplace_back(u);
				}
			}
		}
	}
}

int cnt = 0, maxt = -1;
vector<int> temp;
void dfs(int s, int v) {
	if (v == s) {
		++cnt;
		temp.emplace_back(v);
		int sumt = accumulate(temp.begin(), temp.end(), 0, [](int acc, int idx) -> int {
			return acc + t[idx];
		});
		if (sumt > maxt) {
			maxt = sumt;
		}
		temp.pop_back();
		return;
	}
	temp.emplace_back(v);
	for (int i = 0; i < (int)pre[v].size(); i++) {
		dfs(s, pre[v][i]);
	}
	temp.pop_back();
}

int main(int argc, char const *argv[]) {

	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	d.resize(n, INT_MAX), vis.resize(n, false);
	t.resize(n), pre.resize(n), g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < m; i++) {
		int id1, id2, l;
		cin >> id1 >> id2 >> l;
		g[id1].emplace_back(id2, l);
		g[id2].emplace_back(id1, l);
	}
	dijkstra(c1);
	dfs(c1, c2);
	cout << cnt << " " << maxt << "\n";

	return 0;
}