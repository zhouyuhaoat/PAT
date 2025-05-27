/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 20:46:37
 *	modified:	2023-04-04 21:01:01
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=1071785301894295552 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1154 Vertex Coloring
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785301894295552
*/

// @pintia code=start
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge.emplace_back(u, v);
    }
    int k;
    cin >> k;
    while (k--) {
        vector<int> color(n);
        unordered_set<int> colors;
        for (int i = 0; i < n; i++) {
            cin >> color[i];
            colors.emplace(color[i]);
        }
        bool coloring = true;
        for (auto [u, v] : edge) {
            if (color[u] == color[v]) {
                // no two vertices sharing the same edge have the same color
                coloring = false;
                break;
            }
        }
        if (coloring) {
            cout << colors.size() << "-coloring\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end
