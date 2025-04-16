/*
 *	author:		zhouyuhao
 *	created:	2024-05-06 11:44:41
 *	modified:	2024-05-06 11:50:41
 *	item:		Progrmming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805424153280512 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1053 Path of Equal Weight
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805424153280512
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int s;
vector<int> w, tmp;
vector<vector<int>> t, ans;

void dfs(int r, int sum, int l) {
    tmp.resize(l + 1);
    tmp[l] = w[r];
    sum += w[r];
    if (t[r].size() == 0) {
        if (sum == s) ans.emplace_back(tmp);
        return;
    }
    if (sum > s) return;
    for (int i = 0; i < (int)t[r].size(); i++) {
        dfs(t[r][i], sum, l + 1);
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m >> s;
    w.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    t.resize(n);
    vector<bool> isroot(n, true);
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
    int r = find(isroot.begin(), isroot.end(), true) - isroot.begin();
    dfs(r, 0, 0);
    sort(ans.begin(), ans.end(), [](vector<int> a, vector<int> b) {
        // lambda of greater<vector<int>>()
        for (int i = 0; i < min((int)a.size(), (int)b.size()); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return a.size() > b.size();
    });
    for (auto it : ans) {
        for (int i = 0; i < (int)it.size(); i++) {
            cout << it[i];
            i < (int)it.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
