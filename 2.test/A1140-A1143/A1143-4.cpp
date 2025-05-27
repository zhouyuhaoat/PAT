/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 14:15:03
 *	modified:	2023-04-04 14:22:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805343727501312 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1143 Lowest Common Ancestor
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343727501312
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> pre;
unordered_map<int, bool> exist;

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        exist[pre[i]] = true;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int left = u, right = v;
            if (left > right) swap(left, right);
            int lca = -1; // no need to create a tree explicitly, just find the first node in preorder
            for (int i = 0; i < n; i++) {
                if (pre[i] >= left && pre[i] <= right) {
                    lca = pre[i];
                    break;
                }
            }
            if (lca != u && lca != v) {
                cout << "LCA of " << u << " and " << v << " is " << lca << ".\n";
            } else {
                cout << lca << " is an ancestor of " << (lca == u ? v : u) << ".\n";
            }
        } else if (!exist[u] && !exist[v]) {
            cout << "ERROR: " << u << " and " << v << " are not found.\n";
        } else {
            cout << "ERROR: " << (exist[u] ? v : u) << " is not found.\n";
        }
    }

    return 0;
}
// @pintia code=end
