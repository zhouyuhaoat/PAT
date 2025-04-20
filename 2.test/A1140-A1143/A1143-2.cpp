/*
 *	author:		zhouyuhao
 *	created:	2025-04-20 13:28:41
 *	modified:	2025-04-20 14:12:36
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805343727501312 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1143 Lowest Common Ancestor
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343727501312
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
    int v;
    node *lc, *rc;
};

vector<int> pre, in;
unordered_map<int, bool> exist;
unordered_map<int, int> loc;

node *create(node *root, int preR, int inL, int inH) {
    if (inL > inH) {
        return nullptr;
    }
    root = new node;
    root->v = pre[preR];
    int inR = loc[pre[preR]];
    root->lc = create(root->lc, preR + 1, inL, inR - 1);
    root->rc = create(root->rc, preR + (inR - inL) + 1, inR + 1, inH);
    return root;
}

int dfs(node *root, int u, int v) { // LCA of BST: recursion
    if (u < root->v && v < root->v) {
        return dfs(root->lc, u, v);
    }
    if (u > root->v && v > root->v) {
        return dfs(root->rc, u, v);
    }
    return root->v;
}

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        in.emplace_back(pre[i]);
        exist[pre[i]] = true;
    }
    sort(in.begin(), in.end());
    for (int i = 0; i < n; i++) {
        loc[in[i]] = i;
    }
    node *root = create(nullptr, 0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int a = u, b = v;
            if (a > b) {
                swap(a, b);
            }
            int lca = dfs(root, a, b);
            if (lca != u && lca != v) {
                cout << "LCA of " << u << " and " << v << " is " << lca << ".\n";
            } else if (lca == u && lca != v) {
                cout << u << " is an ancestor of " << v << ".\n";
            } else {
                cout << v << " is an ancestor of " << u << ".\n";
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
