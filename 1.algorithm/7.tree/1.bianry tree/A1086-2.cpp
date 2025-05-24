/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 22:14:12
 *	modified:	2023-03-28 22:18:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805380754817024 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1086 Tree Traversals Again
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805380754817024
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

vector<int> pre, in, res;

Node *create(int preR, int inL, int inH) {
    // create binary tree by preorder and inorder
    if (inL > inH) return nullptr;
    int inR = find(in.begin(), in.end(), pre[preR]) - in.begin();
    Node *root = new Node{pre[preR]};
    root->left = create(preR + 1, inL, inR - 1);
    root->right = create(preR + (inR - inL) + 1, inR + 1, inH);
    return root;
}

void postTra(Node *root) { // postorder traversal
    if (!root) return;
    postTra(root->left);
    postTra(root->right);
    res.emplace_back(root->val);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    stack<int> stk;
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;
        if (s == "Push") {
            int val;
            cin >> val;
            stk.emplace(val);
            pre.emplace_back(val);
        } else {
            in.emplace_back(stk.top());
            stk.pop();
        }
    }
    Node *root = create(0, 0, n - 1);
    postTra(root);
    for (int i = 0; i < n; i++) {
        cout << res[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
