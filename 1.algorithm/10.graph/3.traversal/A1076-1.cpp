/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 15:54:25
 *	modified:	2023-03-30 16:21:10
 *	item:		Programming Ability Test
 *	site:		Yuting
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
vector<int> level;
vector<vector<int>> g;

int bfs(int src, int maxLevel) {
    queue<int> q;
    q.emplace(src);
    vis[src] = true;
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i];
            if (level[v] == 0) { // unvisited
                level[v] = level[u] + 1;
            }
            if (!vis[v] && level[v] <= maxLevel) {
                q.emplace(v);
                vis[v] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {

    int n, maxLevel;
    cin >> n >> maxLevel;
    g.resize(n + 1), vis.resize(n + 1), level.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int id;
            cin >> id;
            g[id].emplace_back(i + 1);
        }
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        fill(vis.begin(), vis.end(), false);
        fill(level.begin(), level.end(), 0);
        level[id] = 0;
        cout << bfs(id, maxLevel) << "\n";
    }

    return 0;
}
// @pintia code=end
