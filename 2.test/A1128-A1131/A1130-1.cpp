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

struct node {
    string v;
    int lc, rc;
};

vector<node> t;
string ans;

void dfs(int r) {
    bool nonLeaf = t[r].lc != -1 || t[r].rc != -1; // non-leaf node
    if (nonLeaf) {
        ans += "(";
    }
    if (t[r].lc != -1) {
        dfs(t[r].lc);
    }
    ans += t[r].v;
    if (t[r].rc != -1) {
        dfs(t[r].rc);
    }
    if (nonLeaf) {
        ans += ")";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n + 1);
    vector<bool> isroot(n + 1, true);
    for (int i = 1; i <= n; i++) {
        cin >> t[i].v >> t[i].lc >> t[i].rc;
        if (t[i].lc != -1) {
            isroot[t[i].lc] = false;
        }
        if (t[i].rc != -1) {
            isroot[t[i].rc] = false;
        }
    }
    int r = find(isroot.begin() + 1, isroot.end(), true) - isroot.begin();
    dfs(r); // inorder traversal for infix expression
    // same as non-leaf node, the parentheses of root are not needed
    if (ans[0] == '(') { // parentheses of root: at the beginning and end
        cout << ans.substr(1, ans.size() - 2) << "\n"; // remove the outer parentheses
    } else {
        cout << ans << "\n";
    }

    return 0;
}
// @pintia code=end
