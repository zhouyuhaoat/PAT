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
#include <queue>

using namespace std;

vector<int> dist, team;
vector<vector<int>> pre;
vector<vector<pair<int, int>>> g;

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {dist, val}
    q.emplace(0, src);
    while (!q.empty()) {
        auto [dis, u] = q.top();
        q.pop();
        if (dis > dist[u]) continue; // no vis check
        for (auto [v, dis] : g[u]) {
            if (dist[u] + dis < dist[v]) {
                dist[v] = dist[u] + dis;
                pre[v] = {u}; // clear + emplace_back
                q.emplace(dist[v], v);
            } else if (dist[u] + dis == dist[v]) {
                pre[v].emplace_back(u);
            }
        }
    }
}

int path = 0, maxTeam = -1;
void dfs(int u, int src, int sum) {
    sum += team[u]; // update the information during dfs
    if (u == src) {
        path++;
        maxTeam = max(maxTeam, sum);
        return;
    }
    for (int v : pre[u]) {
        dfs(v, src, sum);
    }
}

int main(int argc, char const *argv[]) {

    int n, m, src, dst;
    cin >> n >> m >> src >> dst;
    dist.resize(n, INT_MAX);
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
    dfs(dst, src, 0);
    cout << path << " " << maxTeam << "\n";

    return 0;
}
// @pintia code=end
