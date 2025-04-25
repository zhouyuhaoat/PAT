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
    int val, dist;
    node(int val, int dist) : val(val), dist(dist) {
    }
    friend bool operator<(node a, node b) {
        return a.dist > b.dist;
    }
};

vector<bool> vis;
vector<int> dist, team;
vector<vector<int>> pre; // predecessor
vector<vector<node>> g;

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<node> q;
    q.emplace(src, 0);
    while (!q.empty()) {
        node top = q.top();
        q.pop();
        int u = top.val;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].val;
            if (!vis[v]) {
                if (dist[u] + g[u][i].dist < dist[v]) {
                    dist[v] = dist[u] + g[u][i].dist;
                    pre[v].clear();
                    pre[v].emplace_back(u);
                    q.emplace(v, dist[v]);
                } else if (dist[u] + g[u][i].dist == dist[v]) {
                    pre[v].emplace_back(u);
                }
            }
        }
    }
}

// predecessor + dfs: backtracking to find all paths
int path = 0, maxTeam = -1;
vector<int> temp;
void dfs(int u, int src) {
    if (u == src) {
        path++;
        temp.emplace_back(u);
        int sum = accumulate(temp.begin(), temp.end(), 0, [](int acc, int idx) -> int {
            return acc + team[idx];
        });
        if (sum > maxTeam) {
            maxTeam = sum;
        }
        temp.pop_back();
        return;
    }
    temp.emplace_back(u);
    for (int i = 0; i < (int)pre[u].size(); i++) {
        dfs(pre[u][i], src);
    }
    temp.pop_back(); // backtracking
}

int main(int argc, char const *argv[]) {

    int n, m, src, dst;
    cin >> n >> m >> src >> dst;
    dist.resize(n, INT_MAX), vis.resize(n);
    team.resize(n), pre.resize(n), g.resize(n);
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
    dfs(dst, src);
    cout << path << " " << maxTeam << "\n";

    return 0;
}
// @pintia code=end
