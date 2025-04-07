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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    // positive: black; negative: red
    int v, bh; // black height
    node *lc, *rc;
};

vector<int> pre, in;

int getbh(node *r) {
    return !r ? 0 : r->bh;
}

void updatebh(node *r) {
    r->bh = max(getbh(r->lc), getbh(r->rc));
    if (r->v > 0) r->bh++;
}

node *create(int r, int s, int e, bool& flag) { // build tree from pre-order and in-order
    if (s > e) return nullptr;
    int i = find(in.begin(), in.end(), pre[r]) - in.begin();
    if (!(i >= s && i <= e)) { // check if the in-order is valid
        flag = false;
        return nullptr;
    }
    node *root = new node;
    root->v = pre[r];
    if (root->v > 0) root->bh = 1;
    root->lc = create(r + 1, s, i - 1, flag);
    root->rc = create(r + i - s + 1, i + 1, e, flag);
    updatebh(root); // from bottom to top
    return root;
}

void dfs(node *root, bool& flag) { // Is It A Red-Black Tree
    if (root->v < 0) {
        // property 4: If a node is red, then both its children are black.
        if (root->lc && root->lc->v < 0) {
            flag = false;
            return;
        }
        if (root->rc && root->rc->v < 0) {
            flag = false;
            return;
        }
    }
    // property 5: For each node, all simple paths from the node to descendant leaves
    // contain the same number of black nodes.
    if (getbh(root->lc) != getbh(root->rc)) {
        flag = false;
        return;
    }
    if (!root->lc && !root->rc) return;
    if (root->lc) dfs(root->lc, flag);
    if (root->rc) dfs(root->rc, flag);
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int n;
        cin >> n;
        pre.resize(n), in.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
            in[i] = pre[i];
        }
        // property 2: The root is black.
        if (pre[0] < 0) {
            cout << "No\n";
            continue;
        }
        // The in-order traversal of a red-black tree is a sorted sequence of numbers,
        // since red-black tree is a binary search tree.
        sort(in.begin(), in.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        bool flag = true;
        node *root = create(0, 0, n - 1, flag);
        if (!flag) { // not a binary search tree
            cout << "No\n";
            continue;
        }
        dfs(root, flag);
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end