/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 13:46:25
 *	modified:	2023-04-05 14:16:38
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635126488367104 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1159 Structure of a Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635126488367104
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int val, level;
    Node *parent, *left, *right;
};

vector<int> post;
unordered_map<int, int> loc;
unordered_map<int, Node *> tree;
bool isFull = true;

Node *create(int postR, int inL, int inH, int level, Node *parent) {
    if (inL > inH) return nullptr;
    Node *root = new Node{post[postR], level, parent, nullptr, nullptr};
    int inR = loc[post[postR]];
    root->left = create(postR - (inH - inR) - 1, inL, inR - 1, level + 1, root);
    root->right = create(postR - 1, inR + 1, inH, level + 1, root);
    tree[root->val] = root;
    if ((!root->left && root->right) || (root->left && !root->right)) {
        isFull = false;
    }
    return root;
}

bool judge(string s) { // judge the relationship by pointer in a binary tree
    int a, b;
    if (s.find("root") != string::npos) {
        sscanf(s.c_str(), "%d is the root", &a);
        return tree[a]->parent == nullptr; // root's parent is null
    } else if (s.find("siblings") != string::npos) {
        sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
        return a != b && tree[a]->parent == tree[b]->parent;
    } else if (s.find("parent") != string::npos) {
        sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
        return tree[a] == tree[b]->parent;
    } else if (s.find("left") != string::npos) {
        sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
        return tree[a] == tree[b]->left;
    } else if (s.find("right") != string::npos) {
        sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
        return tree[a] == tree[b]->right;
    } else if (s.find("level") != string::npos) {
        sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
        return tree[a]->level == tree[b]->level;
    } else if (s.find("full") != string::npos) {
        return isFull;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        loc[v] = i;
    }
    create(n - 1, 0, n - 1, 1, nullptr);
    int m;
    cin >> m;
    getchar();
    for (int q = 0; q < m; q++) {
        string s;
        getline(cin, s);
        judge(s) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
