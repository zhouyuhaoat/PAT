/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 17:34:14
 *	modified:	2023-04-02 18:42:09
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805355987451904 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1115 Counting Nodes in a Binary Search Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805355987451904
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

struct node {
    int v;
    node *lc, *rc; // left child, right child
};

void insert(node *&r, int v) { // build a binary search tree
    if (r == nullptr) {
        r = new node{v, nullptr, nullptr};
        return;
    }
    if (v <= r->v) {
        insert(r->lc, v);
    } else {
        insert(r->rc, v);
    }
}

int maxl = -1; // max level
map<int, int> cnt;
void dfs(node *r, int l) {
    ++cnt[l];
    maxl = max(maxl, l);
    if (r->lc != nullptr) {
        dfs(r->lc, l + 1);
    }
    if (r->rc != nullptr) {
        dfs(r->rc, l + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node *r = nullptr;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        insert(r, v);
    }
    dfs(r, 1);
    cout << cnt[maxl] << " + " << cnt[maxl - 1] << " = " << cnt[maxl] + cnt[maxl - 1] << "\n";

    return 0;
}
// @pintia code=end