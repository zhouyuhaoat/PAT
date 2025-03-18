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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> t, path;

void dfs(int r, int n) {
    if (2 * r + 1 >= n) {
        if (r < n) {
            path.emplace_back(t[r]);
            for (int i = 0; i < (int)path.size(); i++) {
                cout << path[i];
                i < (int)path.size() - 1 ? cout << " " : cout << "\n";
            }
            path.pop_back();
        }
        return;
    }
    path.emplace_back(t[r]);
    dfs(2 * r + 2, n);
    path.pop_back();
    path.emplace_back(t[r]);
    dfs(2 * r + 1, n);
    path.pop_back();
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    dfs(0, n); // 0-based index
    if (is_heap(t.begin(), t.end())) {
        cout << "Max Heap\n";
    } else if (is_heap(t.begin(), t.end(), greater<int>())) {
        cout << "Min Heap\n";
    } else {
        cout << "Not Heap\n";
    }

    return 0;
}
// @pintia code=end