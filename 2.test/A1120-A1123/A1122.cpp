/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:12:38
 *	modified:	2023-04-03 02:25:25
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805351814119424 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1122 Hamiltonian Cycle
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805351814119424
*/

// @pintia code=start
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> g;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    g.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1][v2] = g[v2][v1] = 1;
    }
    // Hamilton cycle: a simple cycle that contains every vertex in a graph
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int nn;
        cin >> nn;
        vector<int> p(nn); // path
        set<int> v; // vertex
        for (int i = 0; i < nn; i++) {
            cin >> p[i];
            v.emplace(p[i]);
        }
        if ((int)v.size() != n) { // if not all vertex
            cout << "NO\n";
            continue;
        }
        bool isrea = true; // is reachable
        set<int> spp; // whether repeated
        for (int i = 1; i < nn; i++) {
            spp.emplace(p[i]);
            if (g[p[i - 1]][p[i]] != 1) {
                isrea = false;
                break;
            }
        }
        if (!isrea || (int)spp.size() != nn - 1) {
            cout << "NO\n";
            continue;
        }
        if (p[0] != p[nn - 1]) { // if not a cycle
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

    return 0;
}
// @pintia code=end