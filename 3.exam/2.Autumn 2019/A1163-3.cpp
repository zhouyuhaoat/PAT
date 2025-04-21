/*
 *	author:		zhouyuhao
 *	created:	2025-04-21 20:10:52
 *	modified:	2025-04-21 20:36:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1478635670373253120 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1163 Dijkstra Sequence
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635670373253120
*/

// @pintia code=start
#include <climits>
#include <iostream>
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

vector<int> d;
vector<bool> vis;
vector<vector<node>> g;

bool dijkstra(int n, vector<int>& p) {
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), INT_MAX);
    priority_queue<node> q;
    d[p[1]] = 0;
    for (int i = 1; i <= n; i++) {
        int u = p[i];
        vis[u] = true;
        while (!q.empty() && vis[q.top().v]) { // not yet visited
            q.pop();
        }
        if (!q.empty() && q.top().dis < d[u]) { // the smaller minimum distance
            return false;
        }
        for (auto [v, dis] : g[u]) {
            if (!vis[v] && d[u] + dis < d[v]) {
                d[v] = d[u] + dis;
                q.emplace(v, d[v]);
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int nv, ne;
    cin >> nv >> ne;
    d.resize(nv + 1), vis.resize(nv + 1), g.resize(nv + 1);
    for (int i = 0; i < ne; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c), g[b].emplace_back(a, c);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        vector<int> p(nv + 1);
        for (int i = 1; i <= nv; i++) {
            cin >> p[i];
        }
        dijkstra(nv, p) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
