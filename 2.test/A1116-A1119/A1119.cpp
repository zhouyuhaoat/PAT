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

bool isunq = true; // unique
vector<int> pre, in, post;

void intra(int prel, int preh, int postl, int posth) { // inorder traversal
    if (prel == preh) { // base case: only one node
        in.emplace_back(pre[prel]);
        return;
    }
    if (pre[prel] == post[posth]) {
        int root = find(pre.begin() + 1, pre.end(), post[posth - 1]) - pre.begin(); // root of right subtree
        if (root - prel - 1 > 0) { // the size of left subtree
            intra(prel + 1, root - 1, postl, postl + (root - prel) - 1 - 1);
            // left subtree: [prel + 1, root - 1], [postl, postl + (root - prel - 1) - 1]
        } else { // left subtree is empty
            isunq = false;
        }
        in.emplace_back(post[posth]);
        intra(root, preh, postl + (root - prel) - 1, posth - 1);
        // right subtree: [root, preh], [postl + (root - prel - 1), posth - 1]
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    intra(0, n - 1, 0, n - 1);
    if (isunq) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end