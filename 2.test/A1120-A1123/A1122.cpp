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
        vector<int> path(N);
        unordered_set<int> vertex;
        for (int i = 0; i < N; i++) {
            cin >> path[i];
            vertex.emplace(path[i]);
        }
        if (N != n + 1 || path[0] != path[N - 1] || (int)vertex.size() != n) {
            // if not all vertex, or not a cycle, or repeated
            cout << "NO\n";
            continue;
        }
        bool reachable = true;
        for (int i = 1; i < N; i++) {
            if (!g[path[i - 1]][path[i]]) {
                reachable = false;
                break;
            }
        }
        reachable ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
