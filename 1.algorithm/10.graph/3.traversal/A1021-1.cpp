/*
 *	author:		zhouyuhao
 *	created:	2023-03-30 13:46:48
 *	modified:	2023-03-30 14:31:26
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805482919673856 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1021 Deepest Root
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805482919673856
*/

// @pintia code=start
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int maxl = -1;
vector<bool> vis;
vector<int> f, tmp;
set<int> ans;
vector<vector<int>> g;

void dfs(int s, int l) {
    vis[s] = true;
    if (l > maxl) {
        maxl = l;
        tmp.clear();
        tmp.emplace_back(s);
    } else if (l == maxl) {
        tmp.emplace_back(s);
    }
    for (int i = 0; i < (int)g[s].size(); i++) {
        if (!vis[g[s][i]]) {
            dfs(g[s][i], l + 1);
        }
    }
}

int find(int x) {
    int a = x;
    while (x != f[x]) {
        x = f[x];
    }
    while (a != f[a]) {
        int z = a;
        a = f[a], f[z] = x;
    }
    return x;
}

void joint(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
        f[fa] = fb;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    g.resize(n + 1), f.resize(n + 1);
    iota(f.begin(), f.end(), 0);
    vis.resize(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        g[s].emplace_back(e);
        g[e].emplace_back(s);
        joint(s, e);
    }
    // connected components by dsu
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int fi = find(i);
        if (!vis[fi]) {
            ++cnt;
            vis[fi] = true;
        }
    }
    if (cnt == 1) {
        // find the deepest roots of the tree by 2 dfs
        fill(vis.begin(), vis.end(), false);
        dfs(1, 1);
        set<int> ans(tmp.begin(), tmp.end());
        fill(vis.begin(), vis.end(), false);
        dfs(tmp[0], 1);
        ans.insert(tmp.begin(), tmp.end());
        for (auto it : ans) {
            cout << it << "\n";
        }
    } else {
        cout << "Error: " << cnt << " components\n";
    }

    return 0;
}
// @pintia code=end