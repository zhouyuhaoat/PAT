/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 03:19:31
 *	modified:	2023-04-03 03:41:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805349394006016 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1127 ZigZagging on a Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805349394006016
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    node *lc, *rc;
};

vector<int> in, post;
map<int, vector<int>> t;

void create(int postR, int inL, int inH, int l) {
    // build tree by inorder and postorder
    if (inL > inH) {
        return;
    }
    t[l].emplace_back(post[postR]);
    int inR = find(in.begin(), in.end(), post[postR]) - in.begin();
    create(postR - (inH - inR) - 1, inL, inR - 1, l + 1); // size of right subtree: inH - inR
    create(postR - 1, inR + 1, inH, l + 1);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n), post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    create(n - 1, 0, n - 1, 1);
    vector<int> ans;
    for (auto it : t) { // zigzag level order traversal
        if (it.first % 2 != 0) {
            ans.insert(ans.end(), it.second.rbegin(), it.second.rend());
        } else {
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        i < (int)ans.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
