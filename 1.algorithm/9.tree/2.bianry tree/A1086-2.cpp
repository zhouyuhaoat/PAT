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

struct node {
    int v;
    node *lc, *rc;
};

vector<int> pre, in, ans;

node *create(int r, int s, int e) {
    // create binary tree by preorder and inorder
    // r: root index, s: start index, e: end index
    if (s > e) return nullptr;
    int i = find(in.begin(), in.end(), pre[r]) - in.begin();
    node *root = new node;
    root->lc = create(r + 1, s, i - 1);
    root->rc = create(r + (i - s) + 1, i + 1, e);
    root->v = pre[r];
    return root;
}

void posttra(node *r) { // postorder traversal
    if (r->lc != nullptr) posttra(r->lc);
    if (r->rc != nullptr) posttra(r->rc);
    ans.emplace_back(r->v);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < 2 * n; i++) {
        string ss;
        cin >> ss;
        if (ss.size() == 4) {
            int num;
            cin >> num;
            s.emplace(num);
            pre.emplace_back(num);
            // preorder: the order of push in stack
        } else {
            in.emplace_back(s.top());
            s.pop();
            // inorder: the order of pop in stack
        }
    }
    node *r = create(0, 0, n - 1);
    posttra(r);
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
