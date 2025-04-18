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
#include <map>
#include <vector>

using namespace std;

vector<int> pre, ans;
map<int, int> in; // index in inorder
map<int, bool> vis;

void pretra(int r, int s, int e, int l) {
    // create a binary tree by preorder traversal and inorder traversal
    if (s > e) {
        return;
    }
    if (!vis[l]) { // new level
        vis[l] = true;
        ans.emplace_back(pre[r]); // the first node in the level for left-view of binary tree
    }
    int i = in[pre[r]];
    pretra(r + 1, s, i - 1, l + 1);
    pretra(r + (i - s) + 1, i + 1, e, l + 1);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        in[v] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    pretra(0, 0, n - 1, 0);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end