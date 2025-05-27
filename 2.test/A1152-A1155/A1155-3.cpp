/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 17:27:21
 *	modified:	2024-05-15 17:35:46
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

bool isMaxHeap = true, isMinHeap = true;
vector<int> tree, path;

void dfs(int root, int n) {
    path.emplace_back(tree[root]);
    if (2 * root + 1 >= n) {
        if (root < n) {
            for (int i = 0; i < (int)path.size(); i++) {
                if (i > 0) { // path: parent -> child
                    if (path[i - 1] < path[i]) {
                        isMaxHeap = false;
                    } else if (path[i - 1] > path[i]) {
                        isMinHeap = false;
                    }
                    cout << " ";
                }
                cout << path[i];
            }
            cout << "\n";
        }
        path.pop_back();
        return;
    }
    dfs(2 * root + 2, n);
    dfs(2 * root + 1, n);
    path.pop_back();
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    dfs(0, n);
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
