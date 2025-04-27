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
    int val, height, level, id;
    node *left, *right;
};

int getHeight(node *root) {
    return root ? root->height : 0;
}

void updateHeight(node *root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFactor(node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

node *connect34(node *a, node *b, node *c, node *t0, node *t1, node *t2, node *t3) { // balance
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
    a->left = t0, a->right = t1, updateHeight(a);
    c->left = t2, c->right = t3, updateHeight(c);
    b->left = a, b->right = c, updateHeight(b);
    return b;
}

void insert(node *& root, int val) {
    if (!root) {
        root = new node{val, 1, 0, 0, nullptr, nullptr};
        return;
    }
    if (val < root->val) {
        insert(root->left, val), updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) { // 00
                root = connect34(root->left->left, root->left, root,
                    root->left->left->left, root->left->left->right, root->left->right, root->right);
            } else if (getBalanceFactor(root->left) == -1) { // 01
                root = connect34(root->left, root->left->right, root,
                    root->left->left, root->left->right->left, root->left->right->right, root->right);
            }
        }
    } else {
        insert(root->right, val), updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == 1) { // 10
                root = connect34(root, root->right->left, root->right,
                    root->left, root->right->left->left, root->right->left->right, root->right->right);
            } else if (getBalanceFactor(root->right) == -1) { // 11
                root = connect34(root, root->right, root->right->right,
                    root->left, root->right->left, root->right->right->left, root->right->right->right);
            }
        }
    }
}

vector<node> res;
void dfs(node *root, int level, int id) {
    if (!root) return;
    root->level = level, root->id = id;
    res.emplace_back(*root);
    dfs(root->left, level + 1, 2 * id + 1);
    dfs(root->right, level + 1, 2 * id + 2);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }
    dfs(root, 1, 0); // level order traversal after dfs
    sort(res.begin(), res.end(), [](node a, node b) {
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
    // complete AVL tree: AVL + complete binary tree
    res[n - 1].id == n - 1 ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
// @pintia code=end
