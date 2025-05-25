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

struct Node {
    int val, dist, cost;
    Node(int val, int dist, int cost) : val(val), dist(dist), cost(cost) {
    }
    friend bool operator<(Node a, Node b) {
        return a.dist > b.dist;
    }
};

vector<bool> vis;
vector<int> dist, cost, pre;
vector<vector<Node>> g;

void dijkstra(int src) {
    dist[src] = 0, cost[src] = 0;
    priority_queue<Node> q;
    q.emplace(src, 0, 0);
    while (!q.empty()) {
        auto [u, dis, _] = q.top();
        q.pop();
        if (vis[u] || dis > dist[u]) continue;
        vis[u] = true;
        for (auto [v, dis, c] : g[u]) {
            if (vis[v]) continue;
            if (dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
                cost[v] = cost[u] + c;
                pre[v] = u;
                q.emplace(v, dist[v], cost[v]);
            } else if (dist[u] + dis == dist[v]) {
                if (cost[u] + c < cost[v]) {
                    cost[v] = cost[u] + c;
                    pre[v] = u;
                }
            }
        }
    }
}

vector<int> res;
void dfs(int u, int src) {
    if (u == src) {
        res.emplace_back(u);
        return;
    }
    dfs(pre[u], src);
    res.emplace_back(u);
}

int main(int argc, char const *argv[]) {

    int n, m, src, dst;
    cin >> n >> m >> src >> dst;
    dist.resize(n, INT_MAX), cost.resize(n, INT_MAX);
    pre.resize(n), vis.resize(n), g.resize(n);
    for (int i = 0; i < m; i++) {
        int c1, c2, dist, cost;
        cin >> c1 >> c2 >> dist >> cost;
        g[c1].emplace_back(c2, dist, cost);
        g[c2].emplace_back(c1, dist, cost);
    }
    dijkstra(src);
    dfs(dst, src);
    for (int path : res) {
        cout << path << " ";
    }
    cout << dist[dst] << " " << cost[dst] << "\n";

    return 0;
}
// @pintia code=end
