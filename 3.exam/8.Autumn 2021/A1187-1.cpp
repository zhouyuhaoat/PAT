/*
 *	author:		zhouyuhao
 *	created:	2025-04-03 17:46:13
 *	modified:	2025-04-03 17:55:09
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1187 Sorted Cartesian Tree
*/

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

/*
    A Sorted Cartesian tree is a tree of (key, priority) pairs.
    1. The tree is heap-ordered according to the priority values,
    2. and an inorder traversal gives the keys in sorted order.
*/

struct Node {
    int key, priority;
    int left = -1, right = -1;
};

vector<Node> tree;
vector<int> level;

int insert(int root, int val) { // keys: inorder sorted
    if (root == -1) return val;
    if (tree[val].key < tree[root].key) {
        tree[root].left = insert(tree[root].left, val);
    } else {
        tree[root].right = insert(tree[root].right, val);
    }
    return root;
}

void bfs(int root) {
    queue<int> q;
    q.emplace(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        level.emplace_back(node);
        if (tree[node].left != -1) q.emplace(tree[node].left);
        if (tree[node].right != -1) q.emplace(tree[node].right);
    }
}

int main(int argc, char *argv[]) {

    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + 1].key >> tree[i + 1].priority;
    }
    sort(tree.begin() + 1, tree.end(), [](Node a, Node b) { // priority: (min) heap-ordered
        return a.priority < b.priority;
    });
    int root = -1;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);
    }
    bfs(root);
    for (int i = 0; i < (int)level.size(); i++) {
        cout << tree[level[i]].key;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < (int)level.size(); i++) {
        cout << tree[level[i]].priority;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
