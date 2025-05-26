/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:37:03
 *	modified:	2023-04-02 22:16:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805359372255232 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1110 Complete Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805359372255232
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val, id;
    int left, right;
};

vector<bool> isRoot;
vector<Node> tree;

int getID(string s) { // get id from string, not char
    if (isdigit(s[0])) {
        isRoot[stoi(s)] = false;
        return stoi(s);
    } else {
        return -1; // -1 means null
    }
}

void dfs(int root, int id) {
    if (root == -1) return;
    tree[root].id = id;
    dfs(tree[root].left, 2 * id + 1);
    dfs(tree[root].right, 2 * id + 2);
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n), isRoot.resize(n, true);
    for (int i = 0; i < n; i++) {
        string left, right;
        cin >> left >> right;
        tree[i] = {i, 0, getID(left), getID(right)};
    }
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();
    dfs(root, 0);
    sort(tree.begin(), tree.end(), [](Node a, Node b) {
        return a.id < b.id;
    });
    for (int i = 0; i < n; i++) { // if CBT, the id should be in ascending order, from 0 to n-1.
        if (tree[i].id != i) {
            cout << "NO " << root << "\n";
            return 0;
        }
    }
    cout << "YES " << tree[n - 1].val << "\n";

    return 0;
}
// @pintia code=end
