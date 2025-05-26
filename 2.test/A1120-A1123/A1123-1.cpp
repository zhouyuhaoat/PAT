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

Node *connect34(Node *a, Node *b, Node *c, Node *t0, Node *t1, Node *t2, Node *t3) { // balance
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

Node *insert(Node *root, int val) {
    if (!root) {
        return new Node{val, 1, nullptr, nullptr};
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
        updateHeight(root);
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
        root->right = insert(root->right, val);
        updateHeight(root);
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
        if (!node) { // if nullptr
            flag = true;
            continue; // then all nodes after it must be nullptr
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
    // complete AVL tree: AVL + complete binary tree
    isComplete ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
// @pintia code=end
