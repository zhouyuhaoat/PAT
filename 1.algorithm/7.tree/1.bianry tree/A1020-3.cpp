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

struct Node {
    int val;
    Node *left, *right;
};

vector<int> post, in, level;

Node *create(int postL, int postH, int inL, int inH) {
    if (inL > inH) return nullptr;
    Node *root = new Node{post[postH]}; // postH = postR
    int inR = find(in.begin(), in.end(), post[postH]) - in.begin();
    // minus right subtree
    root->left = create(postL, postH - (inH - inR) - 1, inL, inR - 1);
    root->right = create(postH - (inH - inR), postH - 1, inR + 1, inH);
    return root;
}

void bfs(Node *root) {
    queue<Node *> q;
    q.emplace(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        if (!node) continue;
        level.emplace_back(node->val);
        q.emplace(node->left);
        q.emplace(node->right);
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
    Node *root = create(0, n - 1, 0, n - 1);
    bfs(root);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
