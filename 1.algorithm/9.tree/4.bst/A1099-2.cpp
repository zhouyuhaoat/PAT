/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 21:06:04
 *	modified:	2023-03-29 21:10:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805367987355648 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1099 Build A Binary Search Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805367987355648
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int v, l, i; // value, level, index
    int lc, rc; // index of left child, right child
};

vector<node> t;
vector<int> in;
int n, front = 0;

void intra(int r, int l, int i) {
    if (r == -1 || r >= n) return;
    intra(t[r].lc, l + 1, 2 * i + 1);
    t[r].v = in[front++], t[r].l = l, t[r].i = i;
    intra(t[r].rc, l + 1, 2 * i + 2);
}

int main(int argc, char const *argv[]) {

    cin >> n;
    t.resize(n);
    vector<bool> isroot(n, true);
    for (int i = 0; i < n; i++) {
        cin >> t[i].lc >> t[i].rc;
        if (t[i].lc != -1) {
            isroot[t[i].lc] = false;
        }
        if (t[i].rc != -1) {
            isroot[t[i].rc] = false;
        }
    }
    int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    // in order of BST: sorted
    sort(in.begin(), in.end());
    intra(r, 1, 0);
    // level order traversal by sorting with level and index
    sort(t.begin(), t.end(), [](node a, node b) -> bool {
        if (a.l != b.l) {
            return a.l < b.l;
        } else {
            return a.i < b.i;
        }
    });
    for (int i = 0; i < n; i++) {
        cout << t[i].v;
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end