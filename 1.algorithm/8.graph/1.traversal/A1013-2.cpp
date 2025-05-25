/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 13:32:42
 *	modified:	2023-03-30 13:45:37
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
#include <numeric>
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

int main(int argc, char const *argv[]) {

    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> vis(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        g[c1].emplace_back(c2);
        g[c2].emplace_back(c1);
    }
    for (int q = 0; q < k; q++) {
        int id;
        cin >> id;
        DisjointSetUnion dsu(n + 1);
        fill(vis.begin(), vis.end(), false);
        for (int u = 1; u <= n; u++) {
            for (int v : g[u]) {
                if (u != id && v != id) { // remove the city
                    dsu.unite(u, v);
                }
            }
        }
        int cnt = 0; // connected components by dsu
        for (int i = 1; i <= n; i++) {
            if (i != id) {
                int root = dsu.find(i);
                if (!vis[root]) {
                    cnt++;
                    vis[root] = true;
                }
            }
        }
        cout << cnt - 1 << "\n";
    }

    return 0;
}
// @pintia code=end
