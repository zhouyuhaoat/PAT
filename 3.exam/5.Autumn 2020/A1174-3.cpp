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

struct node {
    int v;
    node *lc, *rc;
};

vector<int> pre, ans;
unordered_map<int, int> loc;

node *preTra(int preR, int inL, int inH) {
    if (inL > inH) {
        return nullptr;
    }
    node *root = new node;
    root->v = pre[preR];
    int inR = loc[pre[preR]];
    root->lc = preTra(preR + 1, inL, inR - 1);
    root->rc = preTra(preR + (inR - inL) + 1, inR + 1, inH);
    return root;
}

void dfs(node *root, int l) {
    if (!root) return;
    if (l == (int)ans.size()) { // first time visiting this level
        ans.emplace_back(root->v);
    }
    dfs(root->lc, l + 1);
    dfs(root->rc, l + 1);
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
    node *root = preTra(0, 0, n - 1);
    dfs(root, 0);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
