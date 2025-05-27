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

Node *create(int preR, int inL, int inH) {
    // create binary search tree from preorder and inorder traversal
    if (inL > inH) return nullptr;
    Node *root = new Node{pre[preR]};
    int inR = loc[pre[preR]];
    root->left = create(preR + 1, inL, inR - 1);
    root->right = create(preR + (inR - inL) + 1, inR + 1, inH); // left subtree size: inR - inL
    return root;
}

Node *dfs(Node *root, int u, int v) { // LCA of Binary Tree
    // don't use -1 as a marker, because -1 may be a valid node value
    if (!root || root->val == u || root->val == v) return root; // candidate of LCA
    Node *left = dfs(root->left, u, v);
    Node *right = dfs(root->right, u, v);
    if (left && right) return root; // both or different sides
    return left == nullptr ? right : left; // one or same side, or null
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
    Node *root = create(0, 0, n - 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (exist[u] && exist[v]) {
            int lca = dfs(root, u, v)->val; // no need to ensure left <= right
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
