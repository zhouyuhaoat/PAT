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
    int v;
    node *lc, *rc;
};

vector<int> post, in, level;

node *create(int r, int s, int e) {
    // create binary tree by post-order and in-order traversal
    // r: root index, s: start index, e: end index
    if (s > e) return nullptr;
    node *root = new node{post[r]};
    int i = find(in.begin(), in.end(), post[r]) - in.begin();
    root->lc = create(r - (e - i) - 1, s, i - 1);
    root->rc = create(r - 1, i + 1, e);
    return root;
}

void bfs(node *r) { // level order traversal by BFS
    queue<node *> q;
    q.emplace(r);
    while (!q.empty()) {
        node *t = q.front();
        q.pop();
        level.emplace_back(t->v);
        if (t->lc != nullptr) q.emplace(t->lc);
        if (t->rc != nullptr) q.emplace(t->rc);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    node *r = create(n - 1, 0, n - 1);
    bfs(r);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
