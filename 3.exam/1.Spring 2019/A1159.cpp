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
#include <map>
#include <vector>

using namespace std;

struct node {
    int v, i, l; // value, index, level
    node *lc, *rc;
};

vector<int> post;
map<int, int> loc; // location: value -> index
map<int, node *> t;
bool isfbt = true; // full binary tree

node *create(node *root, int r, int s, int e, int i, int l) {
    // create a binary tree from postorder traversal and inorder traversal
    // r of postorder, s of inorder, e of inorder
    if (s > e) {
        return nullptr;
    }
    root = new node{post[r], i, l, nullptr, nullptr};
    int mi = loc[post[r]];
    root->lc = create(root->lc, r - (e - mi) - 1, s, mi - 1, 2 * i, l + 1);
    root->rc = create(root->rc, r - 1, mi + 1, e, 2 * i + 1, l + 1);
    t[root->v] = root;
    // check if the tree is a full binary tree by checking the number of children
    if ((root->lc == nullptr && root->rc != nullptr) || (root->lc != nullptr && root->rc == nullptr)) {
        isfbt = false;
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
    create(nullptr, n - 1, 0, n - 1, 1, 1); // 1-based index
    int m;
    cin >> m;
    getchar(); // consume the newline character
    for (int q = 0; q < m; q++) {
        string s;
        getline(cin, s);
        bool flag = false;
        // judge the relationship by index in a binary tree
        if (s.find("root") != string::npos) {
            int r;
            sscanf(s.c_str(), "%d is the root", &r);
            if (t[r]->i == 1) { // root is the first node
                flag = true;
            }
        } else if (s.find("siblings") != string::npos) {
            int u, v;
            sscanf(s.c_str(), "%d and %d are siblings", &u, &v);
            if (t[u]->i != t[v]->i && t[u]->i / 2 == t[v]->i / 2) { // siblings have the same parent
                // precondition: u != v
                flag = true;
            }
        } else if (s.find("parent") != string::npos) {
            int pa, ch;
            sscanf(s.c_str(), "%d is the parent of %d", &pa, &ch);
            if (t[ch]->i / 2 == t[pa]->i) { // parent is half of child
                flag = true;
            }
        } else if (s.find("left") != string::npos) {
            int lc, pa;
            sscanf(s.c_str(), "%d is the left child of %d", &lc, &pa);
            if (t[lc]->i == t[pa]->i * 2) { // left child is double of parent
                flag = true;
            }
        } else if (s.find("right") != string::npos) {
            int rc, pa;
            sscanf(s.c_str(), "%d is the right child of %d", &rc, &pa);
            if (t[rc]->i == t[pa]->i * 2 + 1) { // right child is double of parent + 1
                flag = true;
            }
        } else if (s.find("level") != string::npos) {
            int u, v;
            sscanf(s.c_str(), "%d and %d are on the same level", &u, &v);
            if (t[u]->l == t[v]->l) {
                flag = true;
            }
        } else if (s.find("full") != string::npos) {
            if (isfbt) {
                flag = true;
            }
        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
// @pintia code=end