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
#include <vector>

using namespace std;

struct Node {
    int val, dist;
    Node(int val, int dis) : val(val), dist(dis) {
    }
};

vector<int> dist;
vector<bool> vis;
vector<vector<Node>> g;

bool dijkstra(int V, vector<int>& seq) {
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[seq[1]] = 0;
    for (int i = 1; i <= V; i++) { // source -> destination
        int u = seq[i];
        vis[u] = true;
        for (int v = 1; v <= V; v++) {
            if (!vis[v] && dist[v] < dist[u]) {
                /*
                    if Dijkstra sequence, the current node must be the minimum distance node
                    1. not yet visited
                    2. has a smaller minimum distance from source
                */
                return false;
            }
        }
        for (auto [v, dis] : g[u]) { // explore and relax
            if (!vis[v] && dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
            }
        }
    }
    return true;
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
        vector<int> seq(V + 1);
        for (int i = 1; i <= V; i++) {
            cin >> seq[i];
        }
        dijkstra(V, seq) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
