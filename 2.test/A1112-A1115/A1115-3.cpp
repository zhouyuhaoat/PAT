/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 18:45:52
 *	modified:	2023-04-02 18:54:21
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
#include <queue>
#include <unordered_map>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

node *insert(node *root, int val) {
    if (!root) {
        root = new node{val, nullptr, nullptr};
        return root;
    }
    if (val <= root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int maxLevel = -1;
unordered_map<int, int> cnt;
void bfs(node *root) { // dfs -> bfs
    queue<pair<node *, int>> q;
    q.emplace(root, 1);
    while (!q.empty()) {
        auto [cur, level] = q.front();
        q.pop();
        if (!cur) continue;
        cnt[level]++;
        maxLevel = max(maxLevel, level);
        q.emplace(cur->left, level + 1);
        q.emplace(cur->right, level + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    bfs(root);
    cout << cnt[maxLevel] << " + " << cnt[maxLevel - 1] << " = " << cnt[maxLevel] + cnt[maxLevel - 1] << "\n";

    return 0;
}
// @pintia code=end
