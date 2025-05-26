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

bool isUnique = true;
vector<int> pre, in, post;

void inTra(int preL, int preH, int postL, int postH) { // preR = preL, postR = postH
    if (preL == preH) { // base case: only one node
        in.emplace_back(pre[preL]);
        return;
    }
    int rightR = find(pre.begin() + 1, pre.end(), post[postH - 1]) - pre.begin();
    // assume right subtree is always non-empty, if there is one non-empty subtree and one empty subtree
    if (rightR - preL - 1 > 0) { // the size of left subtree
        inTra(preL + 1, rightR - 1, postL, postL + (rightR - preL - 1) - 1);
    } else { // left subtree is empty => not unique
        isUnique = false;
    }
    in.emplace_back(pre[preL]);
    inTra(rightR, preH, postL + (rightR - preL - 1), postH - 1);
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
    inTra(0, n - 1, 0, n - 1);
    isUnique ? cout << "Yes\n" : cout << "No\n";
    for (int i = 0; i < n; i++) {
        cout << in[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
