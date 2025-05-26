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

struct Node {
    int val, height, level, id;
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
        root = new Node{val, 1, 0, 0, nullptr, nullptr};
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

vector<Node> res;
void dfs(Node *root, int level, int id) {
    if (!root) return;
    root->level = level, root->id = id;
    res.emplace_back(*root);
    dfs(root->left, level + 1, 2 * id + 1);
    dfs(root->right, level + 1, 2 * id + 2);
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
    dfs(root, 1, 0);
    sort(res.begin(), res.end(), [](Node a, Node b) {
        if (a.level != b.level) {
            return a.level < b.level;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0; i < n; i++) {
        cout << res[i].val;
        i < n - 1 ? cout << " " : cout << "\n";
    }
    res[n - 1].id == n - 1 ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
// @pintia code=end
