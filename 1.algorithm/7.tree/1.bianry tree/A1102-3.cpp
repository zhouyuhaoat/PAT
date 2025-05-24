/*
 *	author:		zhouyuhao
 *	created:	2023-03-28 22:52:29
 *	modified:	2023-03-28 23:22:01
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
#include <queue>

using namespace std;

struct Node {
    int id;
    int left, right;
};

vector<Node> tree;
vector<int> level, in;

void invert(int root) { // recursion
    if (root == -1) return;
    invert(tree[root].left);
    invert(tree[root].right);
    swap(tree[root].left, tree[root].right);
}

void bfs(int root) {
    queue<int> s;
    s.emplace(root);
    while (!s.empty()) {
        int node = s.front();
        s.pop();
        if (node == -1) continue;
        level.emplace_back(node);
        s.emplace(tree[node].left);
        s.emplace(tree[node].right);
    }
}

void inTra(int root) {
    if (root == -1) return;
    inTra(tree[root].left);
    in.emplace_back(root);
    inTra(tree[root].right);
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
        tree[i].left = readChild(isRoot);
        tree[i].right = readChild(isRoot);
    }
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();
    invert(root);
    bfs(root);
    inTra(root);
    for (int i = 0; i < n; i++) {
        cout << level[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << in[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
