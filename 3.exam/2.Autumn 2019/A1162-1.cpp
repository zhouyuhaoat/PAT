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

struct node {
    string v;
    int lc, rc;
};

vector<node> d; // 1-based index

string dfs(int r) { // postfix expression: unary operator, binary operator
    if (d[r].lc != -1 && d[r].rc != -1) { // both left and right children
        return "(" + dfs(d[r].lc) + dfs(d[r].rc) + d[r].v + ")";
    } else if (d[r].rc != -1) { // only right child
        // for the case of only one child, the child must be on the right
        return "(" + d[r].v + dfs(d[r].rc) + ")";
    } else { // no child
        return "(" + d[r].v + ")";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    d.resize(n + 1);
    vector<bool> isroot(n + 1, true);
    for (int i = 1; i <= n; i++) {
        cin >> d[i].v >> d[i].lc >> d[i].rc;
        if (d[i].lc != -1) {
            isroot[d[i].lc] = false;
        }
        if (d[i].rc != -1) {
            isroot[d[i].rc] = false;
        }
    }
    int r = find(isroot.begin() + 1, isroot.end(), true) - isroot.begin();
    cout << dfs(r) << "\n";

    return 0;
}
// @pintia code=end
