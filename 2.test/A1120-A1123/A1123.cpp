/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:25:52
 *	modified:	2023-04-03 02:44:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805351302414336 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1123 Is It a Complete AVL Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805351302414336
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int v, l, i, h; // value, level, index, height
    node *lc, *rc; // left child, right child
};

int geth(node *r) { // get height
    return r == nullptr ? 0 : r->h;
}

void updateh(node *r) { // update height
    r->h = max(geth(r->lc), geth(r->rc)) + 1;
}

int getbf(node *r) { // get balance factor
    return geth(r->lc) - geth(r->rc);
}

node *connect34(node *a, node *b, node *c, node *t0, node *t1, node *t2, node *t3) { // balance
    /*
    g: the lowest node that is unbalanced
    3 generations: g(rand), p(arent), v; 4 subtrees: t0, t1, t2, t3
    inorder invariant: t0 < a < t1 < b < t2 < c < t3
    00:         01:         10:         11:             34:
          g         g         g           g                 b
         / \       / \       / \         / \               / \
        p   3     p   3     0   p       0   p       =>    a   c
       / \       / \           / \         / \           / \ / \
      v   2     0   v         v   3       1   v         0  1 2  3
     / \           / \       / \             / \
    0   1         1   2     1   2           2   3
    */
    a->lc = t0, a->rc = t1, updateh(a);
    c->lc = t2, c->rc = t3, updateh(c);
    b->lc = a, b->rc = c, updateh(b);
    return b;
}

void insert(node *& r, int v) {
    if (r == nullptr) {
        r = new node{v, 0, 0, 1, nullptr, nullptr};
        return;
    }
    if (v < r->v) {
        insert(r->lc, v), updateh(r);
        if (getbf(r) == 2) {
            if (getbf(r->lc) == 1) { // 00
                r = connect34(r->lc->lc, r->lc, r, r->lc->lc->lc, r->lc->lc->rc, r->lc->rc, r->rc);
            } else if (getbf(r->lc) == -1) { // 01
                r = connect34(r->lc, r->lc->rc, r, r->lc->lc, r->lc->rc->lc, r->lc->rc->rc, r->rc);
            }
        }
    } else {
        insert(r->rc, v), updateh(r);
        if (getbf(r) == -2) {
            if (getbf(r->rc) == 1) { // 10
                r = connect34(r, r->rc->lc, r->rc, r->lc, r->rc->lc->lc, r->rc->lc->rc, r->rc->rc);
            } else if (getbf(r->rc) == -1) { // 11
                r = connect34(r, r->rc, r->rc->rc, r->lc, r->rc->lc, r->rc->rc->lc, r->rc->rc->rc);
            }
        }
    }
}

vector<node> ans;
void dfs(node *r, int l, int i) {
    if (r == nullptr) {
        return;
    }
    r->l = l, r->i = i;
    ans.emplace_back(*r);
    dfs(r->lc, l + 1, 2 * i + 1);
    dfs(r->rc, l + 1, 2 * i + 2);
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
    dfs(r, 1, 0); // level order traversal after dfs
    sort(ans.begin(), ans.end(), [](node a, node b) {
        if (a.l != b.l) {
            return a.l < b.l;
        } else {
            return a.i < b.i;
        }
    });
    for (int i = 0; i < n; i++) {
        cout << ans[i].v;
        i < n - 1 ? cout << " " : cout << "\n";
    }
    // complete AVL tree: AVL + complete binary tree
    ans[n - 1].i == n - 1 ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
// @pintia code=end