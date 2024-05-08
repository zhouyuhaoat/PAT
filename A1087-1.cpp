/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 21:36:42
 *	modified:	2023-03-30 22:19:55
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>

using namespace std;

struct city {
	int v, cost;
	city(int v, int cost) : v(v), cost(cost) {
	}
	friend bool operator<(city a, city b) {
		return a.cost > b.cost;
	}
};

vector<bool> vis;
vector<int> h, c;
vector<vector<int>> pre;
vector<vector<city>> g;

void dijkstra(int s) {
	c[s] = 0;
	priority_queue<city> q;
	q.emplace(s, 0);
	while (!q.empty()) {
		city t = q.top();
		q.pop();
		int u = t.v;
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < (int)g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (c[u] + g[u][i].cost < c[v]) {
					c[v] = c[u] + g[u][i].cost;
					pre[v].clear();
					pre[v].emplace_back(u);
					q.emplace(v, c[v]);
				} else if (c[u] + g[u][i].cost == c[v]) {
					pre[v].emplace_back(u);
				}
			}
		}
	}
}

int maxh = -1, cnt = 0;
float maxhavr = -1;
vector<int> ans, temp;
void dfs(int s, int v) {
	if (v == s) {
		++cnt;
		temp.emplace_back(v);
		int sumh = accumulate(temp.begin(), temp.end(), 0, [](int acc, int idx) -> int {
			return acc + h[idx];
		});
		if (sumh > maxh) {
			maxh = sumh;
			maxhavr = (float)sumh / (temp.size() - 1);
			ans = temp;
		} else if (sumh == maxh) {
			float havr = (float)sumh / (temp.size() - 1);
			if (havr > maxhavr) {
				maxhavr = havr;
				ans = temp;
			}
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

	int n, k;
	string s;
	cin >> n >> k >> s;
	c.resize(n, INT_MAX), vis.resize(n, false);
	h.resize(n), pre.resize(n, vector<int>()), g.resize(n);
	map<string, int> mid;
	map<int, string> mstr;
	mid[s] = 0, mstr[0] = s;
	for (int i = 1; i < n; i++) {
		string c;
		cin >> c >> h[i];
		mid[c] = i, mstr[i] = c;
	}
	for (int i = 0; i < k; i++) {
		string c1, c2;
		int cost;
		cin >> c1 >> c2 >> cost;
		g[mid[c1]].emplace_back(mid[c2], cost);
		g[mid[c2]].emplace_back(mid[c1], cost);
	}
	dijkstra(mid[s]);
	int e = mid["ROM"];
	dfs(mid[s], e);
	cout << cnt << " " << c[e] << " " << maxh << " " << (int)maxhavr << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << mstr[ans[i]];
		i > 0 ? cout << "->" : cout << "\n";
	}

	return 0;
}