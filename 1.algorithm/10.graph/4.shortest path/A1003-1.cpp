/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 17:47:38
 *	modified:	2023-03-30 19:06:54
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805523835109376 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1003 Emergency
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805523835109376
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v, dis;
    node(int v, int dis) : v(v), dis(dis) { // constructor
    }
    // overload operator< for priority_queue with min-heap
    friend bool operator<(node a, node b) {
        return a.dis > b.dis;
    }
};

vector<int> t, ct, d, p;
vector<bool> vis;
vector<vector<node>> g;

void dijkstra(int s, int e) {
    d[s] = 0, p[s] = 1, ct[s] = t[s];
    priority_queue<node> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        node f = q.top();
        q.pop();
        int u = f.v;
        if (vis[u]) { // skip if visited
            continue;
        }
        vis[u] = true;
        // relax
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (!vis[v]) {
                if (d[u] + g[u][i].dis < d[v]) {
                    d[v] = d[u] + g[u][i].dis;
                    p[v] = p[u];
                    ct[v] = ct[u] + t[v];
                    q.emplace(v, d[v]);
                } else if (d[u] + g[u][i].dis == d[v]) {
                    p[v] += p[u];
                    if (ct[v] < ct[u] + t[v]) {
                        ct[v] = ct[u] + t[v];
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    d.resize(n, INT_MAX), vis.resize(n, false), p.resize(n, 0);
    t.resize(n), ct.resize(n, 0), g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < m; i++) {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        g[c1].emplace_back(c2, l);
        g[c2].emplace_back(c1, l);
    }
    dijkstra(s, e);
    cout << p[e] << " " << ct[e] << "\n";

    return 0;
}
// @pintia code=end