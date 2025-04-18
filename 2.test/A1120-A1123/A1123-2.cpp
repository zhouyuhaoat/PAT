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
    int v, l, i, h;
    node *lc, *rc;
};

int geth(node *r) {
    return r == nullptr ? 0 : r->h;
}

void updateh(node *r) {
    r->h = max(geth(r->lc), geth(r->rc)) + 1;
}

int getbf(node *r) {
    return geth(r->lc) - geth(r->rc);
}

void L(node *& r) { // 11 -> 34
    node *temp = r->rc;
    r->rc = temp->lc;
    temp->lc = r;
    updateh(r), updateh(temp);
    r = temp;
}

void R(node *& r) { // 00 -> 34
    node *temp = r->lc;
    r->lc = temp->rc;
    temp->rc = r;
    updateh(r), updateh(temp);
    r = temp;
}

void insert(node *& r, int v) {
    if (r == nullptr) {
        r = new node{v, 0, 0, 1, nullptr, nullptr};
        return;
    }
    if (v < r->v) {
        insert(r->lc, v), updateh(r);
        if (getbf(r) == 2) {
            if (getbf(r->lc) == -1) { // 01 -> 00
                L(r->lc);
            }
            R(r); // 00
        }
    } else {
        insert(r->rc, v), updateh(r);
        if (getbf(r) == -2) {
            if (getbf(r->rc) == 1) { // 10 -> 11
                R(r->rc);
            }
            L(r); // 11
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
    dfs(r, 1, 0);
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
    ans[n - 1].i == n - 1 ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
// @pintia code=end
