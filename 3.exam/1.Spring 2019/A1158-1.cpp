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
        if (rootA < rootB) { // union by rank: use smaller number as root, or head
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
        int a, b, t;
        cin >> a >> b >> t;
        duration[a][b] += t;
    }
    vector<int> suspects;
    for (int i = 1; i <= n; i++) {
        int call = 0, callBack = 0;
        for (int j = 1; j <= n; j++) {
            if (duration[i][j] > 0 && duration[i][j] <= 5) {
                call++;
                if (duration[j][i] > 0) {
                    callBack++;
                }
            }
        }
        if (call > k && callBack * 5 <= call) {
            suspects.emplace_back(i); // ordered
        }
    }
    if (suspects.empty()) {
        cout << "None\n";
    } else {
        DisjointSetUnion dsu(n + 1);
        for (int i : suspects) { // two loops for all pairs
            for (int j : suspects) {
                if (duration[i][j] > 0 && duration[j][i] > 0) {
                    dsu.unite(i, j);
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
