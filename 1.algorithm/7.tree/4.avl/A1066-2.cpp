/*
 *	author:		zhouyuhao
 *	created:	2025-04-25 21:35:37
 *	modified:	2025-04-25 22:06:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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

struct Node {
    int val, height;
    Node *left, *right;
};

int getHeight(Node *root) {
    return root ? root->height : 0;
}

void updateHeight(Node *root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFactor(Node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

void L(Node *& root) { // 11 -> 34
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root), updateHeight(temp);
    root = temp;
}

void R(Node *& root) { // 00 -> 34
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root), updateHeight(temp);
    root = temp;
}

void insert(Node *& root, int val) {
    if (!root) {
        root = new Node{val, 1, nullptr, nullptr};
        return;
    }
    if (val < root->val) {
        insert(root->left, val), updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == -1) { // 01 -> 00
                L(root->left);
            }
            R(root); // 00
        }
    } else {
        insert(root->right, val), updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == 1) { // 10 -> 11
                R(root->right);
            }
            L(root); // 11
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }
    cout << root->val << "\n";

    return 0;
}
// @pintia code=end
