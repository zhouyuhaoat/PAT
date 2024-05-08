/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 22:25:16
 *	modified:	2023-03-30 23:12:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

struct sta {
	int v, dis;
	sta(int v, int dis) : v(v), dis(dis) {
	}
	friend bool operator<(sta a, sta b) {
		return a.dis > b.dis;
	}
};

vector<bool> vis;
vector<int> d;
vector<vector<sta>> g;

void dijkstra(int s) {
	fill(d.begin(), d.end(), INT_MAX);
	fill(vis.begin(), vis.end(), false);
	d[s] = 0;
	priority_queue<sta> q;
	q.emplace(s, 0);
	while (!q.empty()) {
		sta t = q.top();
		q.pop();
		int u = t.v;
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < (int)g[u].size(); i++) {
			int v = g[u][i].v;
			if (!vis[v]) {
				if (d[u] + g[u][i].dis < d[v]) {
					d[v] = d[u] + g[u][i].dis;
					q.emplace(v, d[v]);
				}
			}
		}
	}
}

int getid(string s, int n) {
	int id = 0;
	if (!isdigit(s[0])) {
		s.erase(0, 1);
		id += n;
	}
	return id + stoi(s);
}

int main(int argc, char const *argv[]) {

	int n, m, k, ds;
	cin >> n >> m >> k >> ds;
	d.resize(n + m + 1), vis.resize(n + m + 1);
	g.resize(n + m + 1);
	for (int i = 0; i < k; i++) {
		string p1, p2;
		int dist;
		cin >> p1 >> p2 >> dist;
		int id1 = getid(p1, n), id2 = getid(p2, n);
		g[id1].emplace_back(id2, dist);
		g[id2].emplace_back(id1, dist);
	}
	int maxdis = -1, can = -1;
	float avedis = -1;
	for (int s = n + 1; s <= n + m; s++) {
		dijkstra(s);
		int dis = INT_MAX, sumdis = 0;
		bool islaw = true;
		for (int i = 1; i <= n; i++) {
			dis = min(dis, d[i]);
			sumdis += d[i];
			if (d[i] > ds) {
				islaw = false;
				break;
			}
		}
		if (islaw) {
			if (dis > maxdis) {
				maxdis = dis;
				avedis = (float)sumdis / n;
				can = s;
			} else if (dis == maxdis) {
				if ((float)sumdis / n < avedis) {
					avedis = (float)sumdis / n;
					can = s;
				}
			}
		}
	}
	if (can != -1) {
		cout << "G" << can - n << "\n";
		cout << fixed << setprecision(1) << (float)maxdis << " " << fixed << setprecision(1) << avedis << "\n";
	} else {
		cout << "No Solution\n";
	}

	return 0;
}