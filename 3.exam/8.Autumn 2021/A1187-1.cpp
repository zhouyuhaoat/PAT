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
    int key, pri; // key, priority
    node *lc, *rc;
};

vector<node> t, level;

node *insert(node *root, int i) {
    // insert a node with index 'i' into the tree rooted at 'root'
    // and return the root of the tree
    if (!root) {
        root = new node{t[i].key, t[i].pri, nullptr, nullptr};
        return root;
    }
    if (t[i].key < root->key) { // keys: inorder sorted
        root->lc = insert(root->lc, i);
    } else {
        root->rc = insert(root->rc, i);
    }
    return root;
}

void leveltra(node root) { // level-order traversal
    queue<node> q;
    q.emplace(root);
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        level.emplace_back(t);
        // *: dereference the pointer
        if (t.lc) q.emplace(*t.lc);
        if (t.rc) q.emplace(*t.rc);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> t[i + 1].key >> t[i + 1].pri;
    }
    sort(t.begin() + 1, t.end(), [](node a, node b) { // priority: (min) heap-ordered
        return a.pri < b.pri;
    });
    node *root = nullptr;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);
    }
    leveltra(*root);
    for (int i = 0; i < (int)level.size(); i++) {
        cout << level[i].key;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }
    for (int i = 0; i < (int)level.size(); i++) {
        cout << level[i].pri;
        i < (int)level.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}