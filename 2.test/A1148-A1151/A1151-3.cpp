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
    unordered_map<int, int> loc;
    unordered_map<int, bool> exist;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        loc[val] = i;
        exist[val] = true;
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int left = loc[u], right = loc[v];
            if (left > right) swap(left, right);
            int lca = -1;
            for (int i = 0; i < n; i++) { // preorder traversal
                int root = loc[pre[i]];
                /*
                    lca in binary tree is the first node in preorder traversal
                    - whose index in inorder traversal is between left and right
                */
                if (root >= left && root <= right) {
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
