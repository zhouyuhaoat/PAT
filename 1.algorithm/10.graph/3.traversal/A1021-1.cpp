/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 13:46:48
 *	modified:	2023-03-30 14:31:26
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805482919673856 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1021 Deepest Root
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805482919673856
*/

// @pintia code=start
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
    vector<int> f; // father

public:
    DisjointSetUnion(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        return f[x] = find(f[x]); // path compression
    }

    void unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA != rootB) {
            f[rootA] = rootB;
        }
    }
};

int maxDepth = -1;
vector<bool> vis;
vector<int> temp;
vector<vector<int>> g;

void dfs(int u, int depth) {
    vis[u] = true;
    if (depth > maxDepth) {
        maxDepth = depth;
        temp.clear();
        temp.emplace_back(u);
    } else if (depth == maxDepth) {
        temp.emplace_back(u);
    }
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) {
            dfs(v, depth + 1);
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vis.resize(n + 1), g.resize(n + 1);
    DisjointSetUnion dsu(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        dsu.unite(u, v);
    }
    int cnt = 0; // connected components by dsu
    for (int i = 1; i <= n; i++) {
        int root = dsu.find(i);
        if (!vis[root]) {
            cnt++;
            vis[root] = true;
        }
    }
    if (cnt == 1) {
        // find the deepest roots of the tree by 2 dfs
        fill(vis.begin(), vis.end(), false);
        dfs(1, 1);
        set<int> res(temp.begin(), temp.end());
        fill(vis.begin(), vis.end(), false);
        dfs(temp[0], 1);
        res.insert(temp.begin(), temp.end());
        for (int root : res) {
            cout << root << "\n";
        }
    } else {
        cout << "Error: " << cnt << " components\n";
    }

    return 0;
}
// @pintia code=end
