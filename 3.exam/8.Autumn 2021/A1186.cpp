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

void dfs(int u, int s, int &l) {
    vis[u] = true;
    l++;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, s, l);
            return; // choose the next destination with the smallest number
            // only need to visit the neighbor with the smallest id
            // if we want to visit all neighbors, we can remove this return statement and just continue the loop
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
    int s = -1, maxl = -1; // l: length of the path, or level of the tree in the graph
    for (int i = 1; i <= n; i++) {
        fill(vis.begin(), vis.end(), false);
        int l = 0;
        dfs(i, i, l);
        if (maxl < l) {
            maxl = l;
            s = i;
        }
    }
    cout << s << " " << maxl << "\n";

    return 0;
}