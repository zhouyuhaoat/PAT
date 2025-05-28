/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 16:15:13
 *	modified:	2023-04-05 16:33:33
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635060278108160 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1158 Telefraud Detection
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635060278108160
*/

// @pintia code=start
#include <iostream>
#include <map>
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
        if (rootA < rootB) { // union by rank: larger id -> smaller id
            swap(rootA, rootB);
        }
        f[rootA] = rootB;
    }
};

int main(int argc, char const *argv[]) {

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> duration(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        duration[u][v] += t;
    }
    vector<int> suspects;
    for (int u = 1; u <= n; u++) {
        int call = 0, callBack = 0;
        for (int v = 1; v <= n; v++) {
            if (duration[u][v] > 0 && duration[u][v] <= 5) {
                call++;
                if (duration[v][u] > 0) {
                    callBack++;
                }
            }
        }
        if (call > k && callBack * 5 <= call) {
            suspects.emplace_back(u); // ordered
        }
    }
    if (suspects.empty()) {
        cout << "None\n";
    } else {
        DisjointSetUnion dsu(n + 1);
        for (int u : suspects) { // two loops for all pairs
            for (int v : suspects) {
                if (duration[u][v] > 0 && duration[v][u] > 0) {
                    dsu.unite(u, v);
                }
            }
        }
        map<int, vector<int>> gangs;
        for (int suspect : suspects) {
            gangs[dsu.find(suspect)].emplace_back(suspect);
        }
        for (auto [_, gang] : gangs) {
            for (int i = 0; i < (int)gang.size(); i++) {
                cout << gang[i];
                i < (int)gang.size() - 1 ? cout << " " : cout << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
