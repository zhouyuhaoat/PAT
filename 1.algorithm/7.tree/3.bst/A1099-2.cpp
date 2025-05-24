/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 21:06:04
 *	modified:	2023-03-29 21:10:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805367987355648 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1099 Build A Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805367987355648
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val, level, id;
    int left, right;
};

vector<Node> tree;
vector<int> in;
int idx = 0;

void inTra(int root, int level, int id) {
    if (root == -1) return;
    inTra(tree[root].left, level + 1, 2 * id + 1);
    tree[root].val = in[idx++];
    tree[root].level = level, tree[root].id = id;
    inTra(tree[root].right, level + 1, 2 * id + 2);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    inTra(0, 1, 0);
    // level order traversal by sorting with level and index
    sort(tree.begin(), tree.end(), [](Node a, Node b) {
        if (a.level != b.level) {
            return a.level < b.level;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0; i < n; i++) {
        cout << tree[i].val;
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
