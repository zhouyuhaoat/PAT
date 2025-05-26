/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 03:19:31
 *	modified:	2023-04-03 03:41:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805349394006016 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1127 ZigZagging on a Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805349394006016
*/

// @pintia code=start
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

vector<int> in, post;

Node *create(int postR, int inL, int inH) {
    if (inL > inH) return nullptr;
    Node *root = new Node{post[postR]};
    int inR = find(in.begin(), in.end(), post[postR]) - in.begin();
    root->left = create(postR - (inH - inR) - 1, inL, inR - 1);
    root->right = create(postR - 1, inR + 1, inH);
    return root;
}

vector<int> bfs(Node *root) { // zigzag level order traversal
    vector<int> res;
    queue<Node *> q;
    q.emplace(root);
    bool zigzag = false;
    while (!q.empty()) {
        deque<int> level; // use deque to allow insertion at both ends
        for (int i = q.size(); i > 0; i--) {
            Node *node = q.front();
            q.pop();
            zigzag ? level.emplace_back(node->val) : level.emplace_front(node->val);
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        res.insert(res.end(), level.begin(), level.end());
        zigzag = !zigzag;
    }
    return res;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n), post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    Node *root = create(n - 1, 0, n - 1);
    vector<int> res = bfs(root);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
