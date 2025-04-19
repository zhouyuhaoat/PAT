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

string dfs(int r) {
    if (r == -1) { // invalid node
        return "";
    }
    if (t[r].lc == -1 && t[r].rc == -1) { // leaf node: operand
        return t[r].v;
    }
    return "(" + dfs(t[r].lc) + t[r].v + dfs(t[r].rc) + ")"; // non-leaf node: operator
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
    string ans = dfs(r);
    if (n == 1) { // root is the only one operand
        cout << ans << "\n";
    } else { // root is an operator
        cout << ans.substr(1, ans.size() - 2) << "\n";
    }

    return 0;
}
// @pintia code=end
