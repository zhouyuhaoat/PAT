/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 15:08:53
 *	modified:	2023-04-04 15:22:27
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805343043829760 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1146 Topological Order
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343043829760
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> degree; // in degree

bool isTopologicalOrder(vector<int>& seq) {
    vector<int> temp(degree);
    for (int u : seq) {
        if (temp[u] != 0) { // invalid
            return false;
        }
        for (int v : g[u]) {
            temp[v]--;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    g.resize(n + 1), degree.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        degree[v]++;
    }
    int k;
    cin >> k;
    vector<int> res;
    for (int q = 0; q < k; q++) {
        vector<int> seq(n);
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
        }
        if (!isTopologicalOrder(seq)) {
            res.emplace_back(q);
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
