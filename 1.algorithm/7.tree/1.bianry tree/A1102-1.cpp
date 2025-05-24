/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 22:20:41
 *	modified:	2023-03-28 22:52:16
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
    int val, id;
    int left, right;
};

vector<Node> tree;
vector<int> in;

void inTra(int root, int id) {
    // invert the left and right child for inorder traversal
    // invert the index of the left and right child for level order traversal
    if (root == -1) return;
    inTra(tree[root].right, 2 * id);
    tree[root].id = id;
    in.emplace_back(root);
    inTra(tree[root].left, 2 * id + 1);
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
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n);
    vector<bool> isRoot(n, true);
    for (int i = 0; i < n; i++) {
        tree[i].val = i;
        tree[i].left = readChild(isRoot);
        tree[i].right = readChild(isRoot);
    }
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();
    inTra(root, 1);
    // level order traversal by sorting with index
    sort(tree.begin(), tree.end(), [](Node a, Node b) {
        return a.id < b.id;
    });
    for (int i = 0; i < n; i++) {
        cout << tree[i].val;
        i < n - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
