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

vector<int> pre, res;
unordered_map<int, int> loc; // location: index in inorder
unordered_map<int, bool> vis;

void create(int preR, int inL, int inH, int level) {
    // create a binary tree by preorder traversal and inorder traversal
    if (inL > inH) return;
    if (!vis[level]) { // new level
        vis[level] = true;
        res.emplace_back(pre[preR]); // the first node in the level for left-view of binary tree
    }
    int inR = loc[pre[preR]];
    create(preR + 1, inL, inR - 1, level + 1);
    create(preR + (inR - inL) + 1, inR + 1, inH, level + 1); // left subtree size: inR - inL
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
    create(0, 0, n - 1, 0);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
