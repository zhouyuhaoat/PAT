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
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e(m); // edges
    for (int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        unordered_set<int> v; // vertices
        for (int i = 0; i < n; i++) {
            int vertex;
            cin >> vertex;
            v.emplace(vertex);
        }
        bool flag = true;
        for (auto& edge : e) {
            if (v.find(edge.first) == v.end() && v.find(edge.second) == v.end()) {
                // cover: at least one vertex of the edge is in the set
                flag = false;
                break;
            }
        }
        if (flag) { // cover all edges
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end