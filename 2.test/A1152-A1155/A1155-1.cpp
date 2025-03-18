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

vector<int> t, path;

void dfs(int r, int n) {
    if (2 * r + 1 >= n) { // leaf node: right child also must not exist
        // all valid nodes
        path.emplace_back(t[r]);
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i];
            i < (int)path.size() - 1 ? cout << " " : cout << "\n";
        }
        path.pop_back(); // backtracking
        return;
    }
    // right subtree first
    if (2 * r + 2 < n) { // valid node
        path.emplace_back(t[r]);
        dfs(2 * r + 2, n);
        path.pop_back(); // backtracking
    }
    if (2 * r + 1 < n) { // valid node
        path.emplace_back(t[r]);
        dfs(2 * r + 1, n);
        path.pop_back(); // backtracking
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    dfs(0, n); // 0-based index
    bool ismax = true, ismin = true;
    if (t[0] > t[1]) { // possibly be a max heap, can not be a min heap
        for (int i = 0; i < n / 2; i++) {
            // judge whether the parent node is greater than its children
            if (2 * i + 1 < n && t[2 * i + 1] > t[i]) {
                ismax = false;
                break;
            }
            if (2 * i + 2 < n && t[2 * i + 2] > t[i]) {
                ismax = false;
                break;
            }
        }
        if (ismax) {
            cout << "Max Heap\n";
        }
    } else { // possibly be a min heap, can not be a max heap
        for (int i = 0; i < n / 2; i++) {
            // judge whether the parent node is less than its children
            if (2 * i + 1 < n && t[2 * i + 1] < t[i]) {
                ismin = false;
                break;
            }
            if (2 * i + 2 < n && t[2 * i + 2] < t[i]) {
                ismin = false;
                break;
            }
        }
        if (ismin) {
            cout << "Min Heap\n";
        }
    }
    if (!(ismax && ismin)) {
        cout << "Not Heap\n";
    }

    return 0;
}
// @pintia code=end