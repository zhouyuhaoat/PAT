/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 00:44:58
 *	modified:	2023-04-04 09:09:25
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805346063728640 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1135 Is It A Red-Black Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805346063728640
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int v, bh;
    node *lc, *rc;
};

vector<int> pre;

int getBh(node *r) {
    return !r ? 0 : r->bh;
}

void updateBh(node *r) {
    r->bh = max(getBh(r->lc), getBh(r->rc));
    if (r->v > 0) r->bh++;
}

node *insert(node *root, int v) { // suppose the tree is a binary search tree
    if (!root) {
        root = new node{v, v > 0 ? 1 : 0, nullptr, nullptr};
    } else if (abs(v) < abs(root->v)) {
        root->lc = insert(root->lc, v);
    } else {
        root->rc = insert(root->rc, v);
    }
    updateBh(root);
    return root;
}

void dfs(node *root, bool& flag) {
    if (!flag) return;
    if (root->v < 0) {
        if (root->lc && root->lc->v < 0) {
            flag = false;
            return;
        }
        if (root->rc && root->rc->v < 0) {
            flag = false;
            return;
        }
    }
    if (getBh(root->lc) != getBh(root->rc)) {
        flag = false;
        return;
    }
    if (root->lc) dfs(root->lc, flag);
    if (root->rc) dfs(root->rc, flag);
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        pre.resize(n);
        node *root = nullptr;
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
            root = insert(root, pre[i]);
        }
        bool flag = true;
        dfs(root, flag);
        if (pre[0] < 0 || !flag) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
// @pintia code=end
