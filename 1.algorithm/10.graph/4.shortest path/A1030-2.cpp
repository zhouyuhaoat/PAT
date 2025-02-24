/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 20:56:23
 *	modified:	2023-03-30 21:14:50
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
#include <algorithm>
#include <climits>
#include <iostream>
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
vector<int> d;
vector<vector<int>> c, pre;
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

int minc = INT_MAX;
vector<int> tmp, ans;
void dfs(int s, int v) {
    if (v == s) {
        tmp.emplace_back(v);
        int sumc = 0;
        // from the start to the end
        for (int i = tmp.size() - 1; i > 0; i--) {
            sumc += c[tmp[i]][tmp[i - 1]];
        }
        if (sumc < minc) {
            minc = sumc;
            ans = tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.emplace_back(v);
    for (int i = 0; i < (int)pre[v].size(); i++) {
        dfs(s, pre[v][i]);
    }
    tmp.pop_back();
}

int main(int argc, char const *argv[]) {

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    d.resize(n, INT_MAX), vis.resize(n, false);
    c.resize(n, vector<int>(n)), pre.resize(n), g.resize(n);
    for (int i = 0; i < m; i++) {
        int s, e, d, cost;
        cin >> s >> e >> d >> cost;
        g[s].emplace_back(e, d);
        g[e].emplace_back(s, d);
        c[s][e] = c[e][s] = cost;
    }
    dijkstra(s);
    dfs(s, e);
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << d[e] << " " << minc << "\n";

    return 0;
}
// @pintia code=end