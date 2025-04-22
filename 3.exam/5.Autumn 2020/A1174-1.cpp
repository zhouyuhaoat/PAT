/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 14:35:28
 *	modified:	2023-04-14 14:59:21
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1697151678120173570 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1174 Left-View of Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173570
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> pre, ans;
unordered_map<int, int> loc; // index in inorder
unordered_map<int, bool> vis;

void preTra(int preR, int inL, int inH, int l) {
    // create a binary tree by preorder traversal and inorder traversal
    if (inL > inH) {
        return;
    }
    if (!vis[l]) { // new level
        vis[l] = true;
        ans.emplace_back(pre[preR]); // the first node in the level for left-view of binary tree
    }
    int inR = loc[pre[preR]];
    preTra(preR + 1, inL, inR - 1, l + 1);
    preTra(preR + (inR - inL) + 1, inR + 1, inH, l + 1); // left subtree size: inR - inL
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
    preTra(0, 0, n - 1, 0);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
