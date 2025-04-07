/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 00:44:58
 *	modified:	2025-04-07 09:09:25
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805346063728640 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1135 Is It A Red-Black Tree
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805346063728640
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int v, bh;
    node *lc, *rc;
    node(int v, int bh, node *lc, node *rc) : v(v), lc(lc), rc(rc) {
    }
};

int getbh(node *root) {
    return !root ? 0 : root->bh;
}

void updatebh(node *root) {
    root->bh = max(getbh(root->lc), getbh(root->rc));
    if (root->v > 0) root->bh++;
}

node *insert(node *root, int v) { // suppose the tree is a binary search tree
    if (!root) {
        root = new node(v, v > 0 ? 1 : 0, nullptr, nullptr);
    } else if (abs(v) < abs(root->v)) {
        root->lc = insert(root->lc, v);
    } else {
        root->rc = insert(root->rc, v);
    }
    updatebh(root);
    return root;
}

bool judge1(node *root) { // property 4
    if (!root) return true;
    if (root->v < 0) {
        if (root->lc && root->lc->v < 0) return false;
        if (root->rc && root->rc->v < 0) return false;
    }
    return judge1(root->lc) && judge1(root->rc);
}

bool judge2(node *root) { // property 5
    if (!root) return true;
    if (getbh(root->lc) != getbh(root->rc)) return false;
    return judge2(root->lc) && judge2(root->rc);
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        vector<int> pre(n);
        node *root = nullptr;
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
            root = insert(root, pre[i]);
        }
        if (pre[0] < 0 || !judge1(root) || !judge2(root)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
// @pintia code=end