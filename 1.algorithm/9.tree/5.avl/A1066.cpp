/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 21:35:37
 *	modified:	2023-03-29 22:06:17
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805404939173888 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1066 Root of AVL Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805404939173888
*/

// @pintia code=start
#include <iostream>

using namespace std;

struct node {
    int v, h; // h: height
    node *lc, *rc;
} *r;

int geth(node *r) {
    return r == nullptr ? 0 : r->h;
}

void updateh(node *r) {
    r->h = max(geth(r->lc), geth(r->rc)) + 1;
}

int getbf(node *r) { // bf: balance factor
    return geth(r->lc) - geth(r->rc);
}

node *connect34(node *a, node *b, node *c, node *t0, node *t1, node *t2, node *t3) {
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
        r = new node{v, 1, nullptr, nullptr};
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

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        insert(r, v);
    }
    cout << r->v << "\n";

    return 0;
}
// @pintia code=end
