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

vector<int> in, post;
map<int, vector<int>> tree; // level -> nodes

void create(int postR, int inL, int inH, int level) {
    // create a binary tree from inorder and postorder traversals
    if (inL > inH) return;
    tree[level].emplace_back(post[postR]);
    int inR = find(in.begin(), in.end(), post[postR]) - in.begin();
    create(postR - (inH - inR) - 1, inL, inR - 1, level + 1); // right subtree size: inH - inR
    create(postR - 1, inR + 1, inH, level + 1);
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
    vector<int> res;
    for (auto [level, nodes] : tree) { // zigzag level order traversal
        if (level % 2 != 0) {
            res.insert(res.end(), nodes.rbegin(), nodes.rend()); // reverse by reverse iterator
        } else {
            res.insert(res.end(), nodes.begin(), nodes.end());
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
