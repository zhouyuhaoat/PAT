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

struct node {
    int key, priority;
    int left = -1, right = -1;
};

vector<node> tree;
vector<int> level;

int insert(int root, int id) {
    if (root == -1) return id;
    if (tree[id].key < tree[root].key) {
        tree[root].left = insert(tree[root].left, id);
    } else {
        tree[root].right = insert(tree[root].right, id);
    }
    return root;
}

void bfs(int root) {
    queue<int> q;
    q.emplace(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        level.emplace_back(cur);
        if (tree[cur].left != -1) q.emplace(tree[cur].left);
        if (tree[cur].right != -1) q.emplace(tree[cur].right);
    }
}

int main(int argc, char *argv[]) {

    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].key >> tree[i].priority;
    }
    sort(tree.begin() + 1, tree.end(), [](node a, node b) {
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
