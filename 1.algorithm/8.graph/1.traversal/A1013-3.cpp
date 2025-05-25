/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 13:14:40
 *	modified:	2023-03-30 13:30:19
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805500414115840 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1013 Battle Over Cities
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805500414115840
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

vector<bool> vis;
vector<vector<int>> g;

void bfs(int src) {
    queue<int> q;
    q.emplace(src);
    vis[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.emplace(v);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m, k;
    cin >> n >> m >> k;
    vis.resize(n + 1), g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        g[c1].emplace_back(c2);
        g[c2].emplace_back(c1);
    }
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        fill(vis.begin(), vis.end(), false);
        vis[id] = true;
        int cnt = 0; // connected components by bfs
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i);
            }
        }
        cout << cnt - 1 << "\n";
    }

    return 0;
}
// @pintia code=end
