/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 23:24:58
 *	modified:	2023-04-05 23:55:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478636026017230848 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1167 Cartesian Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478636026017230848
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

vector<int> in;

Node *create(int inL, int inH) {
    if (inL > inH) return nullptr;
    int inR = min_element(in.begin() + inL, in.begin() + inH + 1) - in.begin();
    Node *root = new Node{in[inR]};
    root->left = create(inL, inR - 1);
    root->right = create(inR + 1, inH);
    return root;
}

vector<int> bfs(Node *root) {
    vector<int> res;
    queue<Node *> q;
    q.emplace(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        res.emplace_back(node->val);
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
    }
    return res;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    Node *root = create(0, n - 1);
    vector<int> res = bfs(root);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
