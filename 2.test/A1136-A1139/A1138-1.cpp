/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 13:18:46
 *	modified:	2023-04-03 13:27:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805345078067200 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1138 Postorder Traversal
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345078067200
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, in, post;

void postTra(int preR, int inL, int inH) {
    // postorder traversal by preorder and inorder
    if (inL > inH) return;
    int inR = find(in.begin(), in.end(), pre[preR]) - in.begin();
    postTra(preR + 1, inL, inR - 1);
    postTra(preR + (inR - inL) + 1, inR + 1, inH); // left subtree size = inR - inL
    post.emplace_back(pre[preR]);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    postTra(0, 0, n - 1);
    cout << post[0] << "\n";

    return 0;
}
// @pintia code=end
