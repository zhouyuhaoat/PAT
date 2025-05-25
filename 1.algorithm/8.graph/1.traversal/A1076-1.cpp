/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 15:54:25
 *	modified:	2025-04-16 10:05:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805392092020736 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1076 Forwards on Weibo
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805392092020736
*/

// @pintia code=start
#include <iostream>
#include <queue>

using namespace std;

vector<bool> vis;
vector<vector<int>> g;

int bfs(int src, int maxLevel) {
    fill(vis.begin(), vis.end(), false);
    queue<pair<int, int>> q; // {id, level}
    q.emplace(src, 0);
    vis[src] = true;
    int cnt = 0;
    while (!q.empty()) {
        auto [u, level] = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v] && level < maxLevel) {
                vis[v] = true;
                q.emplace(v, level + 1);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {

    int n, maxLevel;
    cin >> n >> maxLevel;
    g.resize(n + 1), vis.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int id;
            cin >> id;
            g[id].emplace_back(i);
        }
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        cout << bfs(id, maxLevel) << "\n";
    }

    return 0;
}
// @pintia code=end
