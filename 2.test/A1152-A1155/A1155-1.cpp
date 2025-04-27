/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 21:01:12
 *	modified:	2023-04-04 21:34:34
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    if (2 * root + 1 >= n) { // leaf node: right child also must not exist
        // all valid nodes since valid before recursion
        path.emplace_back(tree[root]);
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i];
            i < (int)path.size() - 1 ? cout << " " : cout << "\n";
        }
        path.pop_back(); // backtracking
        return;
    }
    // right subtree first
    if (2 * root + 2 < n) { // valid node before recursion
        path.emplace_back(tree[root]);
        dfs(2 * root + 2, n);
        path.pop_back();
    }
    if (2 * root + 1 < n) {
        path.emplace_back(tree[root]);
        dfs(2 * root + 1, n);
        path.pop_back();
    }
}

bool isMaxHeap = true, isMinHeap = true; // suppose it is a max heap, or a min heap
void isHeap(int n) {
    if (tree[0] > tree[1]) { // possibly be a max heap
        isMinHeap = false; // can not be a min heap
        for (int i = 0; i < n / 2; i++) {
            // judge whether the parent node is greater than its children
            if (2 * i + 1 < n && tree[2 * i + 1] > tree[i]) {
                isMaxHeap = false;
                break;
            }
            if (2 * i + 2 < n && tree[2 * i + 2] > tree[i]) {
                isMaxHeap = false;
                break;
            }
        }
    } else { // possibly be a min heap
        isMaxHeap = false; // can not be a max heap
        for (int i = 0; i < n / 2; i++) {
            // judge whether the parent node is less than its children
            if (2 * i + 1 < n && tree[2 * i + 1] < tree[i]) {
                isMinHeap = false;
                break;
            }
            if (2 * i + 2 < n && tree[2 * i + 2] < tree[i]) {
                isMinHeap = false;
                break;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    dfs(0, n); // 0-based index
    isHeap(n);
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
