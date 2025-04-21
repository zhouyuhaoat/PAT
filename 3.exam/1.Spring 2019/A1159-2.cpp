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
    int v, l;
    node *p, *lc, *rc; // parent
};

vector<int> post;
unordered_map<int, int> loc;
unordered_map<int, node *> t;
bool fbt = true;

node *create(int postR, int inL, int inH, int l, node *parent) {
    if (inL > inH) {
        return nullptr;
    }
    node *root = new node{post[postR], l, nullptr, nullptr, nullptr};
    int inR = loc[post[postR]];
    root->p = parent;
    root->lc = create(postR - (inH - inR) - 1, inL, inR - 1, l + 1, root);
    root->rc = create(postR - 1, inR + 1, inH, l + 1, root);
    t[root->v] = root;
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
    create(n - 1, 0, n - 1, 1, nullptr);
    int m;
    cin >> m;
    getchar();
    for (int q = 0; q < m; q++) {
        string s;
        getline(cin, s);
        bool flag = false;
        int a, b;
        if (s.find("root") != string::npos) {
            sscanf(s.c_str(), "%d is the root", &a);
            flag = t[a]->p == nullptr; // root's parent is null
        } else if (s.find("siblings") != string::npos) {
            sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
            flag = a != b && t[a]->p == t[b]->p;
        } else if (s.find("parent") != string::npos) {
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            flag = t[a] == t[b]->p;
        } else if (s.find("left") != string::npos) {
            sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
            flag = t[a] == t[b]->lc;
        } else if (s.find("right") != string::npos) {
            sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
            flag = t[a] == t[b]->rc;
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
