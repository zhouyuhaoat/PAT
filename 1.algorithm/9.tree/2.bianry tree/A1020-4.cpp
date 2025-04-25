/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 21:39:33
 *	modified:	2023-03-28 22:01:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805485033603072 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1020 Tree Traversals
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805485033603072
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

vector<int> post, in, level;

node *create(int postL, int postH, int inL, int inH) {
    if (postL > postH) return nullptr;
    node *root = new node{post[postH]};
    int inR = find(in.begin(), in.end(), post[postH]) - in.begin();
    // add left subtree; left subtree size: inR - inL
    root->left = create(postL, postL + (inR - inL) - 1, inL, inR - 1);
    root->right = create(postL + (inR - inL), postH - 1, inR + 1, inH);
    return root;
}

void bfs(node *root) {
    queue<node *> q;
    q.emplace(root);
    while (!q.empty()) {
        node *cur = q.front();
        q.pop();
        if (!cur) continue;
        level.emplace_back(cur->val);
        q.emplace(cur->left);
        q.emplace(cur->right);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    post.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    node *root = create(0, n - 1, 0, n - 1);
    bfs(root);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
