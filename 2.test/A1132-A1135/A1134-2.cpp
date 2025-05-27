/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 12:17:36
 *	modified:	2023-04-03 12:20:05
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
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n); // edge id of vertex
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].emplace_back(i), edges[b].emplace_back(i);
    }
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<bool> cover(m, false); // edge covered by vertex
        int cnt = 0; // count of covered edges
        for (int i = 0; i < n; i++) {
            int vertex;
            cin >> vertex;
            for (int id : edges[vertex]) {
                if (!cover[id]) {
                    cnt++;
                    cover[id] = true;
                }
            }
        }
        cnt == m ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
