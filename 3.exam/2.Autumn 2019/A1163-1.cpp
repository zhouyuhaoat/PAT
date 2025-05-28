/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 20:10:52
 *	modified:	2023-04-05 20:36:00
 *	item:		Programming Ability Test
 *	site:		Shahu
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

struct Node {
    int val, dist;
    Node(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(Node a, Node b) {
        return a.dist > b.dist;
    }
};

vector<int> dist;
vector<bool> vis;
vector<vector<Node>> g;

void dijkstra(int src) {
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
    priority_queue<Node> q;
    dist[src] = 0, q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, dis] = q.top();
        q.pop();
        if (vis[u] || dis > dist[u]) continue;
        vis[u] = true;
        for (auto [v, dis] : g[u]) {
            if (!vis[v] && dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
                q.emplace(v, dist[v]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int V, E;
    cin >> V >> E;
    dist.resize(V + 1), vis.resize(V + 1), g.resize(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        g[u].emplace_back(v, dis), g[v].emplace_back(u, dis);
    }
    int k;
    cin >> k;
    while (k--) {
        vector<int> seq(V);
        for (int i = 0; i < V; i++) {
            cin >> seq[i];
        }
        dijkstra(seq[0]);
        bool flag = true;
        // Dijkstra Sequence: the nodes in the path are in non-decreasing order of their distances
        for (int i = 1; i < V; i++) {
            if (dist[seq[i]] < dist[seq[i - 1]]) {
                flag = false;
                break;
            }
        }
        flag ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
