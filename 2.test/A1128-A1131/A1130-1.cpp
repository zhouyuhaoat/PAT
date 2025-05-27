/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 10:38:51
 *	modified:	2023-04-03 19:16:53
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805347921805312 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1130 Infix Expression
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805347921805312
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string val;
    int left, right;
};

vector<Node> tree;

string dfs(int root) {
    if (tree[root].left == -1 && tree[root].right == -1) { // leaf node: operand
        return tree[root].val;
    } else if (tree[root].left == -1 && tree[root].right != -1) { // non-leaf node: unary operator
        // for the case of only one child, the child must be on the right
        return "(" + tree[root].val + dfs(tree[root].right) + ")";
    } else { // non-leaf node: binary operator
        return "(" + dfs(tree[root].left) + tree[root].val + dfs(tree[root].right) + ")";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n + 1);
    vector<bool> isRoot(n + 1, true);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1) isRoot[tree[i].left] = false;
        if (tree[i].right != -1) isRoot[tree[i].right] = false;
    }
    int root = find(isRoot.begin() + 1, isRoot.end(), true) - isRoot.begin();
    string res = dfs(root);
    if (res[0] == '(') { // parentheses of root: at the beginning and end
        cout << res.substr(1, res.size() - 2) << "\n"; // remove the outer parentheses
    } else {
        cout << res << "\n";
    }

    return 0;
}
// @pintia code=end
