/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 00:44:58
 *	modified:	2023-04-04 09:09:25
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805346063728640 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1135 Is It A Red-Black Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805346063728640
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val, blackHeight; // positive: black; negative: red
    Node *left, *right;
};

vector<int> pre, in;

int getBlackHeight(Node *root) {
    return root ? root->blackHeight : 0;
}

void updateBlockHeight(Node *root) {
    root->blackHeight = max(getBlackHeight(root->left), getBlackHeight(root->right));
    if (root->val > 0) root->blackHeight++;
}

Node *create(int preR, int inL, int inH, bool& flag) {
    if (inL > inH) return nullptr;
    int inR = find(in.begin(), in.end(), pre[preR]) - in.begin();
    if (!(inR >= inL && inR <= inH)) { // whether the in-order is valid
        flag = false;
        return nullptr;
    }
    Node *root = new Node{pre[preR], pre[preR] > 0};
    root->left = create(preR + 1, inL, inR - 1, flag);
    root->right = create(preR + (inR - inL) + 1, inR + 1, inH, flag); // left subtree size: inR - inL
    updateBlockHeight(root); // from bottom to top
    return root;
}

void dfs(Node *root, bool& flag) { // Is It A Red-Black Tree
    if (!flag) return;
    if (root->val < 0) { // property 4: If a node is red, then both its children are black.
        if (root->left && root->left->val < 0) {
            flag = false;
            return;
        }
        if (root->right && root->right->val < 0) {
            flag = false;
            return;
        }
    }
    /*
        property 5
        - For each node, all simple paths from the node to descendant leaves
        - contain the same number of black nodes.
    */
    if (getBlackHeight(root->left) != getBlackHeight(root->right)) {
        flag = false;
        return;
    }
    if (root->left) dfs(root->left, flag);
    if (root->right) dfs(root->right, flag);
}

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        pre.resize(n), in.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
            in[i] = pre[i];
        }
        if (pre[0] < 0) { // property 2: The root is black.
            cout << "No\n";
            continue;
        }
        /*
            inorder traversal of red-black tree
            - The inorder traversal of a red-black tree is a sorted sequence of numbers,
            - since red-black tree is a binary search tree.
        */
        sort(in.begin(), in.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        bool flag = true;
        Node *root = create(0, 0, n - 1, flag);
        if (!flag) { // not a binary search tree
            cout << "No\n";
            continue;
        }
        dfs(root, flag);
        flag ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
// @pintia code=end
