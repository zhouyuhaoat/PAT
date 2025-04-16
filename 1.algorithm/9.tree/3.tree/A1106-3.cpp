/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 14:53:34
 *	modified:	2023-03-29 14:57:36
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805362341822464 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1106 Lowest Price in Supply Chain
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805362341822464
*/

// @pintia code=start
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

int cnt = 0, ll = INT_MAX;
vector<vector<int>> t;

void bfs(int root, int l) {
    queue<pair<int, int>> q;
    q.emplace(root, l);
    ll = INT_MAX;
    cnt = 0;
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        if (t[node].empty()) {
            if (level < ll) {
                ll = level;
                cnt = 1;
            } else if (level == ll) {
                cnt++;
            }
        } else {
            for (int child : t[node]) {
                q.emplace(child, level + 1);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n;
    double p, r;
    cin >> n >> p >> r;
    r = r / 100 + 1;
    t.resize(n);
    vector<bool> isroot(n, true);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            t[i].emplace_back(id);
            isroot[id] = false;
        }
    }
    int rr = find(isroot.begin(), isroot.end(), true) - isroot.begin();
    bfs(rr, 0);
    cout << fixed << setprecision(4) << p * pow(r, ll) << " " << cnt << "\n";

    return 0;
}
// @pintia code=end
