/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 13:12:14
 *	modified:	2023-03-29 15:00:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805521431773184 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1004 Counting Leaves
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805521431773184
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int h = -1;
map<int, int> cnt;
vector<vector<int>> t;

void dfs(int r, int l) {
    // l: length of the path from root to current node
    h = max(h, l); // height
    if (t[r].empty()) { // leaf node
        ++cnt[l]; // the number of leaf nodes at the level
        return;
    }
    for (int i = 0; i < (int)t[r].size(); i++) {
        dfs(t[r][i], l + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    t.resize(n + 1);
    vector<bool> isroot(n + 1, true);
    for (int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            t[id].emplace_back(c);
            isroot[c] = false;
        }
    }
    int r = find(isroot.begin(), isroot.end(), true) - isroot.begin() + 1;
    dfs(r, 1);
    for (int i = 1; i <= h; i++) {
        cout << cnt[i];
        i <= h - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end