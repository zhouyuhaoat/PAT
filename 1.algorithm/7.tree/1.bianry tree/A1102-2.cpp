/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 23:24:10
 *	modified:	2023-03-28 23:33:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805365537882112 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1102 Invert a Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805365537882112
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

vector<Node> tree, in;

void dfs(int root, int level, int id) {
    // don't need to swap the index of the node
    if (root == -1) return;
    dfs(tree[root].right, level + 1, 2 * id + 1);
    in.emplace_back(Node{root, level, id, -1, -1});
    dfs(tree[root].left, level + 1, 2 * id);
}

int readChild(vector<bool>& isRoot) {
    char ch;
    cin >> ch;
    if (isdigit(ch)) {
        int child = ch - '0';
        isRoot[child] = false;
        return child;
    }
    return -1;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n);
    vector<bool> isRoot(n, true);
    for (int i = 0; i < n; i++) {
        tree[i].left = readChild(isRoot);
        tree[i].right = readChild(isRoot);
    }
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();
    dfs(root, 1, 1);
    vector<Node> level(in);
    // level order traversal by sorting with level and index
    sort(level.begin(), level.end(), [](Node a, Node b) {
        if (a.level != b.level) {
            return a.level < b.level;
        } else {
            return a.id > b.id; // reverse the order of the index
        }
    });
    for (int i = 0; i < n; i++) {
        cout << level[i].val;
        i < n - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i].val;
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
