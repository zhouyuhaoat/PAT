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

struct node {
    int v, i, l; // value, index, level
    node *lc, *rc;
};

vector<int> post;
unordered_map<int, int> loc; // location: value -> index
unordered_map<int, node *> t;
bool fbt = true; // full binary tree

node *create(int postR, int inL, int inH, int id, int l) {
    // create a binary tree from postorder traversal and inorder traversal
    if (inL > inH) {
        return nullptr;
    }
    node *root = new node{post[postR], id, l, nullptr, nullptr};
    int inR = loc[post[postR]]; // right subtree size: inH - inR
    root->lc = create(postR - (inH - inR) - 1, inL, inR - 1, 2 * id, l + 1);
    root->rc = create(postR - 1, inR + 1, inH, 2 * id + 1, l + 1);
    t[root->v] = root;
    // check if the tree is a full binary tree by checking the number of children
    if ((!root->lc && root->rc) || (root->lc && !root->rc)) {
        fbt = false;
    }
    return root;
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
    create(n - 1, 0, n - 1, 1, 1); // 1-based index
    int m;
    cin >> m;
    getchar(); // consume the newline character
    for (int q = 0; q < m; q++) {
        string s;
        getline(cin, s);
        bool flag = false; // judge the relationship by index in a binary tree
        int a, b;
        if (s.find("root") != string::npos) {
            sscanf(s.c_str(), "%d is the root", &a);
            flag = t[a]->i == 1; // root is the first node
        } else if (s.find("siblings") != string::npos) {
            sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
            flag = (a != b && t[a]->i / 2 == t[b]->i / 2); // siblings have the same parent
        } else if (s.find("parent") != string::npos) {
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            flag = t[a]->i == t[b]->i / 2; // parent is half of child
        } else if (s.find("left") != string::npos) {
            sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
            flag = t[a]->i == t[b]->i * 2; // left child is double of parent
        } else if (s.find("right") != string::npos) {
            sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
            flag = t[a]->i == t[b]->i * 2 + 1; // right child is double of parent + 1
        } else if (s.find("level") != string::npos) {
            sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
            flag = t[a]->l == t[b]->l;
        } else if (s.find("full") != string::npos) {
            flag = fbt;
        }
        flag ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
