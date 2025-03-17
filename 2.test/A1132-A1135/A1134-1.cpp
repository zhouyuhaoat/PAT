/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 12:04:27
 *	modified:	2023-04-03 12:17:29
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805346428633088 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1134 Vertex Cover
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805346428633088
*/

// @pintia code=start
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n); // edges of vertex
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].emplace_back(i);
        e[b].emplace_back(i);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        set<int> edge;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            for (auto it : e[v]) {
                edge.emplace(it);
            }
        }
        if ((int)edge.size() == m) { // cover all edges
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end