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

struct Node {
    int val;
    Node *left, *right;
};

vector<int> pre, in;
unordered_map<int, int> loc;
unordered_map<int, bool> exist;

Node *create(int preR, int inL, int inH) {
    if (inL > inH) return nullptr;
    Node *root = new Node{pre[preR]};
    int inR = loc[pre[preR]];
    root->left = create(preR + 1, inL, inR - 1);
    root->right = create(preR + (inR - inL) + 1, inR + 1, inH);
    return root;
}

Node *dfs(Node *root, int u, int v) { // LCA of BST: iteration
    Node *lca = root;
    while (true) {
        if (lca->val > u && lca->val > v) {
            lca = lca->left;
        } else if (lca->val < u && lca->val < v) {
            lca = lca->right;
        } else {
            break;
        }
    }
    return lca;
}

int main(int argc, char const *argv[]) {

    int m, n;
    cin >> m >> n;
    pre.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        in[i] = pre[i];
        exist[pre[i]] = true;
    }
    sort(in.begin(), in.end());
    for (int i = 0; i < n; i++) {
        loc[in[i]] = i;
    }
    Node *root = create(0, 0, n - 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int left = u, right = v;
            if (left > right) swap(left, right);
            int lca = dfs(root, left, right)->val;
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
