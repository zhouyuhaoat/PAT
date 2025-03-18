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

vector<int> t, path;

void dfs(int r, int n) {
    if (r * 2 > n) {
        if (r <= n) { // valid node: possibly out of range
            for (int i = 0; i < (int)path.size(); i++) {
                cout << path[i];
                i < (int)path.size() - 1 ? cout << " " : cout << "\n";
            }
        }
        return;
    }
    path.emplace_back(t[r * 2 + 1]);
    dfs(r * 2 + 1, n);
    path.pop_back();
    path.emplace_back(t[r * 2]);
    dfs(r * 2, n);
    path.pop_back();
}
int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    path.emplace_back(t[1]);
    dfs(1, n); // 1-based index
    bool ismin = true, ismax = true;
    // judge heap property by parent-child relationship in one pass
    for (int i = 2; i <= n && (ismin || ismax); i++) { // until the end or not a heap
        if (t[i / 2] > t[i]) { // possibly be a max heap, can not be a min heap
            ismin = false;
        } else if (t[i / 2] < t[i]) { // possibly be a min heap, can not be a max heap
            ismax = false;
        }
    }
    if (ismin) {
        cout << "Min Heap\n";
    } else if (ismax) {
        cout << "Max Heap\n";
    } else {
        cout << "Not Heap\n";
    }
    return 0;
}
// @pintia code=end