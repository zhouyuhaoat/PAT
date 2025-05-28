/*
 *	author:		zhouyuhao
 *	created:	2024-05-16 21:30:52
 *	modified:	2024-05-16 21:40:03
 *	item:		Programming Ability Test
 *	site:		226, Harbin
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
    string res = "(";
    if (tree[root].left * tree[root].right > 1) { // binary operator
        res += dfs(tree[root].left) + dfs(tree[root].right);
    }
    res += tree[root].val;
    if (tree[root].left * tree[root].right < 0) { // unary operator
        res += dfs(tree[root].right);
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
