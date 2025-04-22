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

vector<vector<int>> d;

struct node {
    int id, dis;
    node(int id, int dis) : id(id), dis(dis) {
    }
    friend bool operator<(node a, node b) {
        if (a.dis != b.dis) {
            return a.dis > b.dis;
        } else {
            return a.id > b.id;
        }
    }
};

void floyd(int n) { // Floyd-Warshall algorithm
    for (int k = 0; k <= n; k++) { // the intermediate node
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // shorter path via k
                } // else: no path
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    d.resize(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        d[u][v] = d[v][u] = dis;
    }
    floyd(n); // all pairs shortest path
    vector<bool> vis(n + 1, false);
    vector<int> ans;
    int sum = 0, src = 0;
    vis[src] = true;
    ans.emplace_back(src);
    while (true) {
        priority_queue<node> q;
        for (int i = 0; i <= n; i++) { // route
            if (!vis[i]) {
                q.emplace(i, d[src][i]);
                // src: the source point in each step
            }
        }
        if (q.empty() || q.top().dis == INT_MAX) {
            break;
        }
        node t = q.top();
        vis[t.id] = true;
        ans.emplace_back(t.id);
        sum += t.dis;
        src = t.id;
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
    }
    if ((int)ans.size() == n + 1) { // all nodes are visited
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
