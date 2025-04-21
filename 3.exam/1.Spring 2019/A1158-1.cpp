/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 16:15:13
 *	modified:	2023-04-05 16:33:33
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478635060278108160 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1158 Telefraud Detection
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635060278108160
*/

// @pintia code=start
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

vector<int> f; // disjoint set union, or union-find

int find(int x) {
    int a = x;
    while (x != f[x]) {
        x = f[x];
    }
    while (a != f[a]) { // path compression
        int z = a;
        a = f[a], f[z] = x;
    }
    return x;
}

void joint(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
        if (fa < fb) { // union by rank
            swap(fa, fb);
        }
        f[fa] = fb;
    }
}

int main(int argc, char const *argv[]) {

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> dur(n + 1, vector<int>(n + 1)); // during
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        dur[a][b] += t;
    }
    vector<int> sus; // suspect
    for (int i = 1; i <= n; i++) {
        int c = 0, cb = 0; // calls, call back
        for (int j = 1; j <= n; j++) {
            if (dur[i][j] > 0 && dur[i][j] <= 5) {
                c++;
                if (dur[j][i] > 0) {
                    cb++;
                }
            }
        }
        if (c > k && cb * 5 <= c) {
            sus.emplace_back(i); // ordered
        }
    }
    if (sus.empty()) {
        cout << "None\n";
    } else {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        for (auto i : sus) { // two loops for all pairs
            for (auto j : sus) {
                if (dur[i][j] > 0 && dur[j][i] > 0) {
                    joint(i, j); // union by rank
                    // use smaller number as root, or head
                }
            }
        }
        map<int, vector<int>> gangs;
        for (auto it : sus) {
            gangs[find(it)].emplace_back(it);
        }
        for (auto [_, gang] : gangs) {
            for (int i = 0; i < (int)gang.size(); i++) {
                cout << gang[i];
                i < (int)gang.size() - 1 ? cout << " " : cout << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
