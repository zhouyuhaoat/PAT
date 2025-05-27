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

struct Node {
    int val, blackHeight;
    Node *left, *right;
};

int getBlackHeight(Node *root) {
    return root ? root->blackHeight : 0;
}

void updateBlockHeight(Node *root) {
    root->blackHeight = max(getBlackHeight(root->left), getBlackHeight(root->right));
    if (root->val > 0) root->blackHeight++;
}

Node *insert(Node *root, int val) { // assume the tree is a binary search tree
    if (!root) {
        root = new Node{val, val > 0, nullptr, nullptr};
    } else if (abs(val) < abs(root->val)) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    updateBlockHeight(root);
    return root;
}

void dfs(Node *root, bool& flag) {
    if (!flag) return;
    if (root->val < 0) { // property 4
        if (root->left && root->left->val < 0) {
            flag = false;
            return;
        }
        if (root->right && root->right->val < 0) {
            flag = false;
            return;
        }
    }
    if (getBlackHeight(root->left) != getBlackHeight(root->right)) { // property 5
        flag = false;
        return;
    }
    if (root->left) dfs(root->left, flag);
    if (root->right) dfs(root->right, flag);
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> pre(n);
        Node *root = nullptr;
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
            root = insert(root, pre[i]);
        }
        bool flag = true;
        dfs(root, flag);
        if (pre[0] < 0 || !flag) { // property 2
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
// @pintia code=end
