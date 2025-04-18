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
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1][v2] = g[v2][v1] = true;
    }
    // Hamilton cycle: a simple cycle that contains every vertex in a graph
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int N;
        cin >> N;
        vector<int> p(N); // path
        unordered_set<int> v;
        for (int i = 0; i < N; i++) {
            cin >> p[i];
            v.emplace(p[i]);
        }
        if (N != n + 1 || p[0] != p[N - 1] || (int)v.size() != n) {
            // if not all vertex, or not a cycle, or repeated
            cout << "NO\n";
            continue;
        }
        bool isRea = true; // reachable
        for (int i = 1; i < N; i++) {
            if (!g[p[i - 1]][p[i]]) {
                isRea = false;
                break;
            }
        }
        isRea ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
