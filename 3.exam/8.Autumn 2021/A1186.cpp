/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:24:13
 *	modified:	2023-04-13 20:48:04
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1186 Playground Exploration
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<set<int>> g;
vector<bool> vis;

void dfs(int u, int& level) {
    vis[u] = true;
    level++;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, level);
            return;
            /*
                choose the next destination with the smallest number
                1. only need to visit the neighbor with the smallest id
                2. if visit all neighbors, remove this return statement and just continue the loop
            */
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    g.resize(n + 1), vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace(v), g[v].emplace(u);
    }
    int src = -1, maxLevel = -1; // length of the path, or level of the tree in the graph
    for (int i = 1; i <= n; i++) {
        fill(vis.begin(), vis.end(), false);
        int level = 0;
        dfs(i, level);
        if (level > maxLevel) {
            maxLevel = level;
            src = i;
        }
    }
    cout << src << " " << maxLevel << "\n";

    return 0;
}
