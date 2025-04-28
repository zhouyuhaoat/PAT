/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 23:24:58
 *	modified:	2023-04-05 23:55:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478636026017230848 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1167 Cartesian Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478636026017230848
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
    int val, id, level; // 0-based index
    node *left, *right;
};

vector<int> in, temp;
unordered_map<int, int> loc;
vector<node> res;

node *create(int inL, int inH, int i, int h) {
    // create a Cartesian tree by inorder traversal
    if (inL > inH) return nullptr;
    temp.assign(in.begin() + inL, in.begin() + inH + 1);
    sort(temp.begin(), temp.end());
    // Cartesian tree is a binary tree that satisfies the (min-)heap property
    node *root = new node{temp[0], i, h};
    int inR = loc[temp[0]];
    root->left = create(inL, inR - 1, 2 * i + 1, h + 1);
    root->right = create(inR + 1, inH, 2 * i + 2, h + 1);
    res.emplace_back(*root);
    return root;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        loc[in[i]] = i;
    }
    create(0, n - 1, 0, 1);
    sort(res.begin(), res.end(), [](node a, node b) { // level order traversal
        if (a.level != b.level) {
            return a.level < b.level;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i].val;
        i < (int)res.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
