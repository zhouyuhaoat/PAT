/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 17:34:14
 *	modified:	2023-04-02 18:42:09
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805355987451904 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1115 Counting Nodes in a Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805355987451904
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

void insert(node *& root, int val) { // build a binary search tree
    // return void with reference to pointer
    if (!root) {
        root = new node{val, nullptr, nullptr};
        return;
    }
    if (val <= root->val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

int maxLevel = -1; // max level
unordered_map<int, int> cnt; // count the number of nodes at each level
void dfs(node *root, int level) {
    cnt[level]++;
    maxLevel = max(maxLevel, level);
    if (root->left) {
        dfs(root->left, level + 1);
    }
    if (root->right) {
        dfs(root->right, level + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }
    dfs(root, 1);
    cout << cnt[maxLevel] << " + " << cnt[maxLevel - 1] << " = " << cnt[maxLevel] + cnt[maxLevel - 1] << "\n";

    return 0;
}
// @pintia code=end
