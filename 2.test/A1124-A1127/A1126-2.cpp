/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:59:48
 *	modified:	2023-04-03 19:08:12
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805349851185152 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1126 Eulerian Path
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805349851185152
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<bool> vis;
vector<vector<int>> g;

void dfs(int u, int& cnt) {
    cnt++;
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, cnt);
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b), g[b].emplace_back(a);
    }
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        g[i].size() % 2 != 0 ? odd++ : even++;
        cout << g[i].size();
        i < n ? cout << " " : cout << "\n";
    }
    vis.resize(n + 1);
    int cnt = 0;
    dfs(1, cnt);
    if (cnt == n) { // all vertices are connected
        if (even == n && odd == 0) {
            cout << "Eulerian\n";
        } else if (odd == 2) {
            cout << "Semi-Eulerian\n";
        } else {
            cout << "Non-Eulerian\n";
        }
    } else {
        cout << "Non-Eulerian\n";
    }

    return 0;
}
// @pintia code=end
