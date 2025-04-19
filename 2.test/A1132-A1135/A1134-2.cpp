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
    vector<vector<int>> e(n); // edges of vertex
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].emplace_back(i), e[b].emplace_back(i);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        vector<bool> edge(m, false);
        int cnt = 0; // count of covered edges
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            for (auto it : e[v]) { // one vertex covers edges
                if (!edge[it]) {
                    cnt++;
                    edge[it] = true;
                }
            }
        }
        cnt == m ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
