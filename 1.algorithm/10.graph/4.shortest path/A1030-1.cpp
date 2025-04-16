/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 19:49:55
 *	modified:	2023-03-31 11:10:12
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805464397627392 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1030 Travel Plan
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805464397627392
*/

// @pintia code=start
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v, dis, cost;
    node(int v, int dis, int cost) : v(v), dis(dis), cost(cost) {
    }
    friend bool operator<(node a, node b) {
        return a.dis > b.dis;
    }
};

vector<bool> vis;
vector<int> d, c, pre; // distance; cost; predecessor
vector<vector<node>> g;

void dijkstra(int s) {
    d[s] = 0, c[s] = 0;
    priority_queue<node> q;
    q.emplace(s, 0, 0);
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
                if (d[u] + g[u][i].dis < d[v]) {
                    d[v] = d[u] + g[u][i].dis;
                    c[v] = c[u] + g[u][i].cost;
                    pre[v] = u;
                    q.emplace(v, d[v], c[v]);
                } else if (d[u] + g[u][i].dis == d[v]) {
                    if (c[u] + g[u][i].cost < c[v]) {
                        c[v] = c[u] + g[u][i].cost;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

vector<int> ans;
void dfs(int s, int v) { // path
    if (v == s) {
        ans.emplace_back(v);
        return;
    }
    dfs(s, pre[v]);
    ans.emplace_back(v);
}

int main(int argc, char const *argv[]) {

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    d.resize(n, INT_MAX), vis.resize(n, false), c.resize(n, INT_MAX);
    pre.resize(n), g.resize(n);
    for (int i = 0; i < m; i++) {
        int c1, c2, dis, cost;
        cin >> c1 >> c2 >> dis >> cost;
        g[c1].emplace_back(c2, dis, cost);
        g[c2].emplace_back(c1, dis, cost);
    }
    dijkstra(s);
    dfs(s, e);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << d[e] << " " << c[e] << "\n";

    return 0;
}
// @pintia code=end
