/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:37:03
 *	modified:	2023-04-02 22:16:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805359372255232 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1110 Complete Binary Tree
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805359372255232
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int left, right;
};

vector<bool> isRoot;
vector<Node> tree;

int getID(string s) {
    if (isdigit(s[0])) {
        isRoot[stoi(s)] = false;
        return stoi(s);
    } else {
        return -1;
    }
}

bool bfs(int root, int n, int& lastNode) {
    queue<int> q;
    q.emplace(root);
    bool flag = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == -1) { // if the node is empty
            flag = true;
            continue; // then all nodes after this should be empty
        }
        if (flag) { // non-empty node after empty node
            return false;
        }
        lastNode = node;
        q.emplace(tree[node].left);
        q.emplace(tree[node].right);
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n), isRoot.resize(n, true);
    for (int i = 0; i < n; i++) {
        string left, right;
        cin >> left >> right;
        tree[i] = {getID(left), getID(right)};
    }
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin(), lastNode = -1;
    if (bfs(root, n, lastNode)) {
        cout << "YES " << lastNode << "\n";
    } else {
        cout << "NO " << root << "\n";
    }

    return 0;
}
// @pintia code=end
