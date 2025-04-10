/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 14:42:37
 *	modified:	2023-04-04 09:53:43
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
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> pre, post;
map<int, int> loc; // location of inorder

void posttra(int r, int s, int e) {
    if (s > e) {
        return;
    }
    int i = loc[pre[r]];
    posttra(r + 1, s, i - 1);
    posttra(r + (i - s) + 1, i + 1, e);
    post.emplace_back(pre[r]);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        loc[in] = i;
    }
    posttra(0, 0, n - 1);
    cout << post[0] << "\n";

    return 0;
}
// @pintia code=end