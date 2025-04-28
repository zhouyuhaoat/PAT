/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 20:48:13
 *	modified:	2023-04-13 22:55:09
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1187 Sorted Cartesian Tree
*/

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// A Sorted Cartesian tree is a tree of (key, priority) pairs.
// 1. The tree is heap-ordered according to the priority values,
// 2. and an inorder traversal gives the keys in sorted order.

struct node {
    int key, priority;
    node *left, *right;
};

vector<node> tree, level;

node *insert(node *root, int id) {
    // insert a node with index 'id' into the tree rooted at 'root'
    // and return the root of the tree
    if (!root) {
        root = new node{tree[id].key, tree[id].priority};
        return root;
    }
    if (tree[id].key < root->key) { // keys: inorder sorted
        root->left = insert(root->left, id);
    } else {
        root->right = insert(root->right, id);
    }
    return root;
}

void bfs(node root) { // level-order traversal
    queue<node> q;
    q.emplace(root);
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        level.emplace_back(t);
        // *: dereference the pointer
        if (t.left) q.emplace(*t.left);
        if (t.right) q.emplace(*t.right);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + 1].key >> tree[i + 1].priority;
    }
    sort(tree.begin() + 1, tree.end(), [](node a, node b) { // priority: (min) heap-ordered
        return a.priority < b.priority;
    });
    node *root = nullptr;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);
    }
    bfs(*root);
    for (int i = 0; i < (int)level.size(); i++) {
        cout << level[i].key;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < (int)level.size(); i++) {
        cout << level[i].priority;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
