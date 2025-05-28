/*
 *	author:		zhouyuhao
 *	created:	2025-04-21 14:26:30
 *	modified:	2025-04-21 14:35:05
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173570 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1174 Left-View of Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173570
*/

// @pintia code=start
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

vector<int> pre, res;
unordered_map<int, int> loc;

Node *create(int preR, int inL, int inH) {
    if (inL > inH) return nullptr;
    Node *root = new Node{pre[preR]};
    int inR = loc[pre[preR]];
    root->left = create(preR + 1, inL, inR - 1);
    root->right = create(preR + (inR - inL) + 1, inR + 1, inH);
    return root;
}

void dfs(Node *root, int level) {
    if (!root) return;
    if (level == (int)res.size()) { // first time visiting this level
        res.emplace_back(root->val);
    }
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        loc[v] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    Node *root = create(0, 0, n - 1);
    dfs(root, 0);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
