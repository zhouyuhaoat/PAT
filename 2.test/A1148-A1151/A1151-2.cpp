/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 15:32:21
 *	modified:	2024-05-15 15:35:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=1038430130011897856 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1151 LCA in a Binary Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038430130011897856
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    vector<int> pre(n);
    unordered_map<int, int> loc; // map -> unordered_map
    unordered_map<int, bool> exist;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        loc[v] = i;
        exist[v] = true;
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int q = 0; q < m; q++) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int uloc = loc[u], vloc = loc[v];
            if (uloc > vloc) {
                swap(uloc, vloc);
            }
            int lca = -1;
            for (int i = 0; i < n; i++) {
                int rloc = loc[pre[i]];
                if (uloc <= rloc && rloc <= vloc) {
                    lca = pre[i]; // find the lca firstly
                    break;
                }
            }
            // then judge the relationship
            if (lca != u && lca != v) {
                cout << "LCA of " << u << " and " << v << " is " << lca << ".\n";
            } else if (lca == u && lca != v) {
                cout << u << " is an ancestor of " << v << ".\n";
            } else if (lca != u && lca == v) {
                cout << v << " is an ancestor of " << u << ".\n";
            } else {
                cout << u << " is an ancestor of " << v << ".\n";
            }
        } else if (exist[u] && !exist[v]) {
            cout << "ERROR: " << v << " is not found.\n";
        } else if (!exist[u] && exist[v]) {
            cout << "ERROR: " << u << " is not found.\n";
        } else {
            cout << "ERROR: " << u << " and " << v << " are not found.\n";
        }
    }

    return 0;
}
// @pintia code=end