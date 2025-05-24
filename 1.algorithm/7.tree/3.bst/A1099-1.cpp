/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 20:39:04
 *	modified:	2023-03-29 21:05:33
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805367987355648 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1099 Build A Binary Search Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805367987355648
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    int left, right;
};

vector<Node> tree;
vector<int> in, res;
int idx = 0;

void inTra(int root) {
    if (root == -1) return;
    inTra(tree[root].left);
    tree[root].val = in[idx++];
    inTra(tree[root].right);
}

void bfs(int root) {
    queue<int> q;
    q.emplace(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == -1) continue;
        res.emplace_back(tree[node].val);
        q.emplace(tree[node].left);
        q.emplace(tree[node].right);
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n), in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end()); // in order of BST: sorted
    inTra(0);
    bfs(0);
    for (int i = 0; i < n; i++) {
        cout << res[i];
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
