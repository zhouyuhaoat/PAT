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
    return [root, mirror](int child) {
        return !mirror ? child >= root : child < root;
    };
}

void postTra(int preL, int preH, vector<int>& post, bool mirror) {
    if (preL > preH) return;
    int root = pre[preL];
    auto pred = makePred(root, mirror);
    int rightR = find_if(pre.begin() + preL + 1, pre.begin() + preH + 1, pred) - pre.begin();
    int rightH = find_if(pre.begin() + rightR, pre.begin() + preH + 1, not_fn(pred)) - pre.begin();
    if (rightH != preH + 1) return; // not a BST
    postTra(preL + 1, rightR - 1, post, mirror);
    postTra(rightR, preH, post, mirror);
    post.emplace_back(root);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    postTra(0, n - 1, post1, true);
    postTra(0, n - 1, post2, false);
    if ((int)post1.size() == n || (int)post2.size() == n) {
        cout << "YES\n";
        auto post = (int)post1.size() == n ? post1 : post2;
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
