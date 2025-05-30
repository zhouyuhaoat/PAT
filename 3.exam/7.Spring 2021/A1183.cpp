/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 18:15:46
 *	modified:	2023-04-13 18:50:17
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1183 Recycling of Shared Bicycles
*/

#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val, dist;
    Node(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(Node a, Node b) {
        if (a.dist != b.dist) {
            return a.dist > b.dist;
        } else {
            return a.val > b.val;
        }
    }
};

vector<vector<int>> dist;

void floyd(int n) { // Floyd-Warshall algorithm
    for (int k = 0; k <= n; k++) { // the intermediate node
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // shorter path via k
                } // else: no path
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    dist.resize(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        dist[u][v] = dist[v][u] = dis;
    }
    floyd(n); // all pairs shortest path
    vector<bool> vis(n + 1, false);
    vector<int> res;
    int sum = 0, src = 0;
    vis[src] = true, res.emplace_back(src);
    while (true) {
        priority_queue<Node> q;
        for (int i = 0; i <= n; i++) { // route
            if (!vis[i]) {
                q.emplace(i, dist[src][i]);
                // src: the source point in each step
            }
        }
        if (q.empty() || q.top().dist == INT_MAX) break;
        auto [val, dist] = q.top(); // next node to visit
        vis[val] = true, res.emplace_back(val);
        sum += dist;
        src = val;
    }
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }
    if ((int)res.size() == n + 1) { // all nodes are visited
        cout << sum << "\n";
    } else {
        vector<int> notVis;
        for (int i = 0; i <= n; i++) {
            if (!vis[i]) {
                notVis.emplace_back(i);
            }
        }
        for (int i = 0; i < (int)notVis.size(); i++) {
            cout << notVis[i];
            i < (int)notVis.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
