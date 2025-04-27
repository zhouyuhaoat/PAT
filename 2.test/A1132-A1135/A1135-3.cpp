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
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val, blackHeight;
    node *left, *right;
};

int getBlackHeight(node *root) {
    return root ? root->blackHeight : 0;
}

void updateBlockHeight(node *root) {
    root->blackHeight = max(getBlackHeight(root->left), getBlackHeight(root->right));
    if (root->val > 0) root->blackHeight++;
}

node *insert(node *root, int val) {
    if (!root) {
        root = new node{val, val > 0, nullptr, nullptr};
    } else if (abs(val) < abs(root->val)) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    updateBlockHeight(root);
    return root;
}

bool judge1(node *root) { // property 4
    if (!root) return true;
    if (root->val < 0) {
        if (root->left && root->left->val < 0) return false;
        if (root->right && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}

bool judge2(node *root) { // property 5
    if (!root) return true;
    if (getBlackHeight(root->left) != getBlackHeight(root->right)) return false;
    return judge2(root->left) && judge2(root->right);
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
