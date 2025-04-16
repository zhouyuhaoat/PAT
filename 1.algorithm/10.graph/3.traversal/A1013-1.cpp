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
#include <vector>

using namespace std;

vector<bool> vis;
vector<vector<int>> g;

void dfs(int s) {
    vis[s] = true;
    for (int i = 0; i < (int)g[s].size(); i++) {
        if (!vis[g[s][i]]) {
            dfs(g[s][i]);
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        g[s].emplace_back(e);
        g[e].emplace_back(s);
    }
    vis.resize(n + 1);
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        fill(vis.begin(), vis.end(), false);
        vis[id] = true; // remove the city
        // connected components by dfs
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i);
            }
        }
        cout << cnt - 1 << "\n";
    }

    return 0;
}
// @pintia code=end
