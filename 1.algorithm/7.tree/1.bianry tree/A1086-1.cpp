/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 20:32:52
 *	modified:	2023-03-28 22:13:59
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

vector<int> pre, in, res;

void postTra(int preR, int inL, int inH) {
    // preorder + inorder -> postorder
    if (inL > inH) return;
    int inR = find(in.begin(), in.end(), pre[preR]) - in.begin();
    postTra(preR + 1, inL, inR - 1);
    postTra(preR + (inR - inL) + 1, inR + 1, inH); // left subtree size: inR - inL
    res.emplace_back(pre[preR]);
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
            pre.emplace_back(val); // preorder: the order of push in stack
        } else {
            in.emplace_back(stk.top()); // inorder: the order of pop in stack
            stk.pop();
        }
    }
    postTra(0, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << res[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
