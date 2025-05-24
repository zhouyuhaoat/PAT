/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 14:14:51
 *	modified:	2023-03-29 18:48:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805440976633856 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1043 Is It a Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805440976633856
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

vector<int> tree, pre, preMirror, post, postMirror;

Node *insert(Node *root, int val) {
    if (!root) {
        return new Node{val};
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void preTra(Node *root, vector<int>& tree) {
    if (!root) return;
    tree.emplace_back(root->val);
    preTra(root->left, tree);
    preTra(root->right, tree);
}

void preTraMirror(Node *root, vector<int>& tree) {
    if (!root) return;
    tree.emplace_back(root->val);
    preTraMirror(root->right, tree);
    preTraMirror(root->left, tree);
}

void postTra(Node *root, vector<int>& tree) {
    if (!root) return;
    postTra(root->left, tree);
    postTra(root->right, tree);
    tree.emplace_back(root->val);
}

void postTraMirror(Node *root, vector<int>& tree) {
    if (!root) return;
    postTraMirror(root->right, tree);
    postTraMirror(root->left, tree);
    tree.emplace_back(root->val);
}

void print(vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i];
        i < (int)vec.size() - 1 ? cout << " " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Node *root = nullptr;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        root = insert(root, tree[i]);
    }
    preTra(root, pre), preTraMirror(root, preMirror);
    postTra(root, post), postTraMirror(root, postMirror);
    if (tree == pre) {
        cout << "YES\n";
        print(post);
    } else if (tree == preMirror) {
        cout << "YES\n";
        print(postMirror);
    } else {
        cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
