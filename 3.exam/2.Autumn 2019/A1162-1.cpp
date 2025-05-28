/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:51:52
 *	modified:	2023-04-05 20:10:36
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635599577522176 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1162 Postfix Expression
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635599577522176
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
    if (tree[root].left != -1 && tree[root].right != -1) { // non-leaf node: binary operator
        return "(" + dfs(tree[root].left) + dfs(tree[root].right) + tree[root].val + ")";
    } else if (tree[root].right != -1) { // non-leaf node: unary operator
        // for the case of only one child, the child must be on the right
        return "(" + tree[root].val + dfs(tree[root].right) + ")";
    } else { // leaf node: operand
        return "(" + tree[root].val + ")";
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
    cout << dfs(root) << "\n";

    return 0;
}
// @pintia code=end
