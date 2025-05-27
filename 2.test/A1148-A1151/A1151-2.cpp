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

struct Node {
    int val;
    Node *left, *right;
};

vector<int> pre, in;
unordered_map<int, int> loc;
unordered_map<int, bool> exist;

int dfs(int preR, int inL, int inH, int u, int v) {
    // lca's index in inorder traversal is between u and v
    int inR = loc[pre[preR]];
    if (inR > u && inR > v) { // left subtree
        return dfs(preR + 1, inL, inR - 1, u, v);
    } else if (inR < u && inR < v) { // right subtree
        return dfs(preR + (inR - inL) + 1, inR + 1, inH, u, v);
    } else { // found
        return pre[preR];
    }
    return -1;
}

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    pre.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        loc[in[i]] = i;
        exist[in[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int left = loc[u], right = loc[v]; // index in inorder traversal
            if (left > right) swap(left, right); // ensure left <= right
            int lca = dfs(0, 0, n - 1, left, right);
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
