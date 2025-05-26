/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 22:17:15
 *	modified:	2023-04-02 22:20:30
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
#include <vector>

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

int maxID = -1, lastNode = -1;
void dfs(int root, int id) {
    if (root == -1) return;
    if (id > maxID) {
        maxID = id;
        lastNode = root;
    }
    dfs(tree[root].left, 2 * id + 1);
    dfs(tree[root].right, 2 * id + 2);
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
    int root = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();
    dfs(root, 0);
    if (maxID >= n) { // if CBT, the maximum id should be n-1
        cout << "NO " << root << "\n";
    } else {
        cout << "YES " << lastNode << "\n";
    }

    return 0;
}
// @pintia code=end
