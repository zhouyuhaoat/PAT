/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 19:07:00
 *	modified:	2023-03-30 19:30:26
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
#include <numeric>
#include <queue>

using namespace std;

struct node {
    int v, dis;
    node(int v, int dis) : v(v), dis(dis) {
    }
    friend bool operator<(node a, node b) {
        return a.dis > b.dis;
    }
};

vector<bool> vis;
vector<int> d, t;
vector<vector<int>> pre; // predecessor
vector<vector<node>> g;

void dijkstra(int s) {
    d[s] = 0;
    priority_queue<node> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        int u = t.v;
        if (vis[u]) { // skip if visited
            continue;
        }
        vis[u] = true;
        // relax & predecessor
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].v;
            if (!vis[v]) {
                if (d[u] + g[u][i].dis < d[v]) {
                    d[v] = d[u] + g[u][i].dis;
                    pre[v].clear();
                    pre[v].emplace_back(u);
                    q.emplace(v, d[v]);
                } else if (d[u] + g[u][i].dis == d[v]) {
                    pre[v].emplace_back(u);
                }
            }
        }
    }
}

// predecessor + dfs: backtracking to find all paths
int p = 0, maxt = -1;
vector<int> tmp;
void dfs(int s, int v) {
    if (v == s) {
        p++;
        tmp.emplace_back(v);
        int sumt = accumulate(tmp.begin(), tmp.end(), 0, [](int acc, int idx) -> int {
            return acc + t[idx];
        });
        if (maxt < sumt) {
            maxt = sumt;
        }
        tmp.pop_back();
        return;
    }
    tmp.emplace_back(v);
    for (int i = 0; i < (int)pre[v].size(); i++) {
        dfs(s, pre[v][i]);
    }
    tmp.pop_back(); // backtracking
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
    cout << p << " " << maxt << "\n";

    return 0;
}
// @pintia code=end
