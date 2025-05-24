/*
 *	author:		zhouyuhao
 *	created:	2025-04-16 13:10:23
 *	modified:	2025-04-16 13:18:19
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805361586847744 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1107 Social Clusters
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805361586847744
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int OFFSET = 1000;
unordered_map<int, vector<int>> g;
unordered_map<int, bool> vis;

void dfs(int u, int& cnt) {
    vis[u] = true;
    if (u < OFFSET) {
        cnt++;
    }
    if (g.count(u) != 0) {
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, cnt);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        getchar();
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            g[i].emplace_back(id + OFFSET);
            g[id + OFFSET].emplace_back(i);
        }
    }
    vector<int> clu;
    for (int i = 0; i < n; i++) {
        if (g.count(i) != 0 && !vis[i]) {
            int size = 0;
            dfs(i, size);
            clu.emplace_back(size);
        }
    }
    sort(clu.begin(), clu.end(), greater<int>());
    cout << clu.size() << "\n";
    for (int i = 0; i < (int)clu.size(); i++) {
        cout << clu[i];
        i < (int)clu.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
