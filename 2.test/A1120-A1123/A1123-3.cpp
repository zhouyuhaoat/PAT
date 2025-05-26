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
#include <queue>

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

Node *L(Node *root) { // 11 -> 34
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root), updateHeight(temp);
    return temp;
}

Node *R(Node *root) { // 00 -> 34
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root), updateHeight(temp);
    return temp;
}

Node *insert(Node *root, int val) {
    if (!root) {
        return new Node{val, 1, nullptr, nullptr};
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == -1) { // 01 -> 00
                root->left = L(root->left);
            }
            root = R(root); // 00
        }
    } else {
        root->right = insert(root->right, val);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == 1) { // 10 -> 11
                root->right = R(root->right);
            }
            root = L(root); // 11
        }
    }
    return root;
}

vector<int> res;
bool isComplete = true;
void bfs(Node *root) {
    queue<Node *> q;
    q.emplace(root);
    bool flag = false;
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (!node) {
            flag = true;
            continue;
        }
        if (flag) {
            isComplete = false;
        }
        res.emplace_back(node->val);
        q.emplace(node->left);
        q.emplace(node->right);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    bfs(root);
    for (int i = 0; i < n; i++) {
        cout << res[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }
    isComplete ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
// @pintia code=end
