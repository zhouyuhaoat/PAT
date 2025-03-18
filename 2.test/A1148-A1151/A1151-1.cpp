/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 18:22:21
 *	modified:	2023-04-04 19:53:46
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=1038430130011897856 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1151 LCA in a Binary Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1038430130011897856
*/

// @pintia code=start
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    vector<int> pre(n);
    map<int, int> loc; // location/index of node in preorder traversal
    map<int, bool> exist;
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
        if (exist[u] && exist[v]) { // found
            int uloc = loc[u], vloc = loc[v]; // index of left and right child
            if (uloc > vloc) { // ensure uloc < vloc
                swap(uloc, vloc);
            }
            int lca = -1;
            for (int i = 0; i < n; i++) {
                int rloc = loc[pre[i]]; // index of root
                // lca in binary tree is the first node whose index is between index of u and v
                if (uloc < rloc && rloc < vloc) {
                    lca = pre[i];
                    break;
                } else if (uloc < rloc && rloc == vloc) {
                    lca = pre[i];
                    break;
                } else if (uloc == rloc && rloc < vloc) {
                    lca = pre[i];
                    break;
                } else if (uloc == rloc && rloc == vloc) {
                    lca = pre[i];
                    break;
                }
            }
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