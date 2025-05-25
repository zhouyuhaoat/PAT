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

struct Node {
    int val, dist;
    Node(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(Node a, Node b) {
        return a.dist > b.dist;
    }
};

vector<int> dist, path, team, maxTeam;
vector<bool> vis;
vector<vector<Node>> g;

void dijkstra(int src) {
    dist[src] = 0, path[src] = 1, maxTeam[src] = team[src];
    priority_queue<Node> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        auto [u, dis] = q.top();
        q.pop();
        if (vis[u] || dis > dist[u]) continue;
        vis[u] = true;
        for (auto [v, dis] : g[u]) {
            if (vis[v]) continue;
            if (dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
                path[v] = path[u];
                maxTeam[v] = maxTeam[u] + team[v];
                q.emplace(v, dist[v]);
            } else if (dist[u] + dis == dist[v]) {
                path[v] += path[u];
                maxTeam[v] = max(maxTeam[v], maxTeam[u] + team[v]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m, src, dst;
    cin >> n >> m >> src >> dst;
    dist.resize(n, INT_MAX), vis.resize(n), path.resize(n);
    team.resize(n), maxTeam.resize(n), g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> team[i];
    }
    for (int i = 0; i < m; i++) {
        int c1, c2, length;
        cin >> c1 >> c2 >> length;
        g[c1].emplace_back(c2, length);
        g[c2].emplace_back(c1, length);
    }
    dijkstra(src);
    cout << path[dst] << " " << maxTeam[dst] << "\n";

    return 0;
}
// @pintia code=end
