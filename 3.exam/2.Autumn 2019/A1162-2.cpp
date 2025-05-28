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
    if (root == -1) return ""; // empty node
    string res = "(";
    if (tree[root].left == -1 && tree[root].right != -1) { // unary operator
        res += tree[root].val;
    }
    res += dfs(tree[root].left) + dfs(tree[root].right);
    if (!(tree[root].left == -1 && tree[root].right != -1)) { // binary operator
        res += tree[root].val;
    }
    res += ")";
    return res;
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
