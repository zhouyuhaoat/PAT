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
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g; // edge
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.emplace_back(a, b);
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        vector<int> c(n);
        set<int> color;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            color.emplace(c[i]);
        }
        bool isclr = true; // validate vertex coloring
        for (auto it : g) {
            if (c[it.first] == c[it.second]) {
                isclr = false;
                break;
            }
        }
        if (isclr) {
            cout << color.size() << "-coloring\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end