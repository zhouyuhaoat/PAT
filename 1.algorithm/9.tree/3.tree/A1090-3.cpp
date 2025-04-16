/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 14:45:53
 *	modified:	2023-03-29 14:50:10
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805376476626944 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1090 Highest Price in Supply Chain
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805376476626944
*/

// @pintia code=start
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

int cnt = 0;
double p, r, ml = -1;
vector<vector<int>> t;

void bfs(int rr, int l) {
    queue<pair<int, int>> q;
    q.emplace(rr, l);
    ml = -1;
    cnt = 0;
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        if (t[node].empty()) {
            if (level > ml) {
                ml = level;
                cnt = 1;
            } else if (level == ml) {
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
    cin >> n >> p >> r;
    r = r / 100 + 1;
    t.resize(n);
    int rr = -1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == -1) {
            rr = i;
        } else {
            t[k].emplace_back(i);
        }
    }
    bfs(rr, 0);
    cout << fixed << setprecision(2) << p * pow(r, ml) << " " << cnt << "\n";

    return 0;
}
// @pintia code=end
