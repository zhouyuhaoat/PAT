/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 23:24:10
 *	modified:	2023-03-28 23:33:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805365537882112 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1102 Invert a Binary Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805365537882112
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int v;
    int lc, rc;
    int l, i;
};

vector<node> d, in;

void dfs(int r, int l, int i) {
    // r: root, l: level, i: index
    // invert the left and right child
    // also the index of the node
    if (d[r].rc != -1) {
        dfs(d[r].rc, l + 1, 2 * i + 1);
    }
    in.emplace_back(node{r, -1, -1, l, i});
    if (d[r].lc != -1) {
        dfs(d[r].lc, l + 1, 2 * i);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    d.resize(n);
    vector<bool> isroot(n, true);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (isdigit(c)) {
            d[i].lc = c - '0';
            isroot[d[i].lc] = false;
        } else {
            d[i].lc = -1;
        }
        cin >> c;
        if (isdigit(c)) {
            d[i].rc = c - '0';
            isroot[d[i].rc] = false;
        } else {
            d[i].rc = -1;
        }
    }
    int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
    dfs(r, 1, 1);
    vector<node> level(in);
    sort(level.begin(), level.end(), [](node a, node b) -> bool {
        if (a.l != b.l) {
            return a.l < b.l;
        } else {
            return a.i > b.i;
        }
    });
    for (int i = 0; i < n; i++) {
        cout << level[i].v;
        i < n - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i].v;
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end