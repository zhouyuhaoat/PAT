/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 17:55:21
 *	modified:	2024-05-15 18:00:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1071785408849047552 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1155 Heap Paths
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785408849047552
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree, path;

void dfs(int root, int n) {
    if (root * 2 > n) { // leaf node & empty node (out of range)
        if (root <= n) { // leaf node
            // no need to emplace and pop itself since emplaced and popped before recursion
            for (int i = 0; i < (int)path.size(); i++) {
                cout << path[i];
                i < (int)path.size() - 1 ? cout << " " : cout << "\n";
            }
        }
        return;
    }
    // right subtree first, then left subtree
    path.emplace_back(tree[root * 2 + 1]);
    dfs(root * 2 + 1, n);
    path.pop_back();
    path.emplace_back(tree[root * 2]);
    dfs(root * 2, n);
    path.pop_back();
}

bool isMaxHeap = true, isMinHeap = true; // assume it is a max heap, and a min heap
void isHeap(vector<int>& heap) {
    // judge heap property by parent-child relationship in one pass
    for (int i = 2; i < (int)heap.size(); i++) {
        if (tree[i / 2] < tree[i]) { // parent < child
            isMaxHeap = false;
        }
        if (tree[i / 2] > tree[i]) { // parent > child
            isMinHeap = false;
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i];
    }
    path.emplace_back(tree[1]); // source of the path
    dfs(1, n); // 1-based index
    isHeap(tree);
    if (isMaxHeap) {
        cout << "Max Heap\n";
    } else if (isMinHeap) {
        cout << "Min Heap\n";
    } else {
        cout << "Not Heap\n";
    }
    return 0;
}
// @pintia code=end
