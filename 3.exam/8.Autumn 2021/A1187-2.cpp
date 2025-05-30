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

struct Node {
    int key, priority;
    Node *left, *right;
};

vector<Node> tree, level;

Node *insert(Node *root, int val) {
    if (!root) {
        return new Node{tree[val].key, tree[val].priority};
    }
    if (tree[val].key < root->key) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void bfs(Node root) {
    queue<Node> q;
    q.emplace(root);
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        level.emplace_back(node);
        // *: dereference the pointer
        if (node.left) q.emplace(*node.left);
        if (node.right) q.emplace(*node.right);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].key >> tree[i].priority;
    }
    sort(tree.begin() + 1, tree.end(), [](Node a, Node b) {
        return a.priority < b.priority;
    });
    Node *root = nullptr;
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
