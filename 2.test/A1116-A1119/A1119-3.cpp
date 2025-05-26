/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 00:50:51
 *	modified:	2023-04-03 01:50:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805353470869504 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1119 Pre- and Post-order Traversals
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805353470869504
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

bool isUnique = true;
vector<int> pre, in, post;

Node *create(int preL, int preH, int postL, int postH) {
    if (preL > preH) return nullptr;
    Node *root = new Node{pre[preL], nullptr, nullptr};
    if (preL == preH) return root;
    if (pre[preL + 1] == post[postH - 1]) {
        isUnique = false;
        root->left = create(preL + 1, preH, postL, postH - 1);
    } else {
        int rightR = find(pre.begin() + preL + 1, pre.begin() + preH + 1, post[postH - 1]) - pre.begin();
        root->left = create(preL + 1, rightR - 1, postL, postL + (rightR - preL - 1) - 1);
        root->right = create(rightR, preH, postL + (rightR - preL) - 1, postH - 1);
    }
    return root;
}

void inTra(Node *root) {
    if (!root) return;
    inTra(root->left);
    in.emplace_back(root->val);
    inTra(root->right);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    Node *root = create(0, n - 1, 0, n - 1);
    inTra(root);
    isUnique ? cout << "Yes\n" : cout << "No\n";
    for (int i = 0; i < n; i++) {
        cout << in[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
