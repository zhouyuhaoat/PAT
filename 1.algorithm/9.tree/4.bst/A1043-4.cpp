/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 12:34:56
 *	modified:	2025-04-16 12:58:21
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805440976633856 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1043 Is It a Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805440976633856
*/

// @pintia code=start
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, post1, post2;

auto makePred(int root, bool mirror) {
    return [root, mirror](int a) {
        return mirror ? a < root : a >= root;
    };
}

void posttra(int r, int e, vector<int>& post, bool mirror) {
    if (r > e) return;
    auto pred = makePred(pre[r], mirror);
    int i = find_if(pre.begin() + r + 1, pre.begin() + e + 1, pred) - pre.begin();
    int j = find_if(pre.begin() + i, pre.begin() + e + 1, not_fn(pred)) - pre.begin();
    // backward search: j, i -> forward search: e, j
    if (j != e + 1) return; // not a BST
    posttra(r + 1, i - 1, post, mirror);
    posttra(i, e, post, mirror);
    post.emplace_back(pre[r]);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    posttra(0, n - 1, post1, true);
    posttra(0, n - 1, post2, false);
    if ((int)post1.size() == n || (int)post2.size() == n) {
        cout << "YES\n";
        auto& post = (int)post1.size() == n ? post1 : post2;
        for (int i = 0; i < n; i++) {
            cout << post[i];
            i < n - 1 ? cout << " " : cout << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
// @pintia code=end
