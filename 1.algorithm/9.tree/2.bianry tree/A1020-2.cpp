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

node *create(int postR, int inL, int inH) {
    // create binary tree by post-order and in-order traversal
    if (inL > inH) return nullptr;
    node *root = new node{post[postR]};
    int inR = find(in.begin(), in.end(), post[postR]) - in.begin();
    root->left = create(postR - (inH - inR) - 1, inL, inR - 1);
    root->right = create(postR - 1, inR + 1, inH);
    return root;
}

void bfs(node *root) { // level order traversal by BFS
    queue<node *> q;
    q.emplace(root);
    while (!q.empty()) {
        node *cur = q.front();
        q.pop();
        level.emplace_back(cur->val);
        if (cur->left) q.emplace(cur->left);
        if (cur->right) q.emplace(cur->right);
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
    node *root = create(n - 1, 0, n - 1);
    bfs(root);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
