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
#include <set>
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
    vector<vector<int>> d(m, vector<int>(3)); // data
    for (int i = 0; i < m; i++) {
        cin >> d[i][0] >> d[i][1] >> d[i][2];
        dur[d[i][0]][d[i][1]] += d[i][2];
    }
    vector<set<int>> rec(n + 1); // record
    for (int i = 0; i < m; i++) {
        if (dur[d[i][0]][d[i][1]] <= 5) {
            rec[d[i][0]].emplace(d[i][1]);
        }
    }
    vector<int> sus; // suspect
    for (int i = 1; i <= n; i++) {
        if ((int)rec[i].size() > k) {
            int cb = 0; // call back
            for (auto it : rec[i]) {
                if (dur[it][i] > 0) {
                    cb++;
                }
            }
            if ((double)cb / rec[i].size() <= 0.2) {
                sus.emplace_back(i);
            }
        }
    }
    if (sus.empty()) {
        cout << "None\n";
    } else {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        for (auto it : sus) { // two loops for all pairs
            for (auto is : sus) {
                if (it != is) {
                    if (dur[it][is] > 0 && dur[is][it] > 0) {
                        joint(it, is); // union by rank: to avoid cycle
                    }
                }
            }
        }
        map<int, vector<int>> gang; // gang, or group
        for (auto it : sus) {
            gang[find(it)].emplace_back(it);
        }
        for (auto it : gang) {
            int size = it.second.size();
            for (auto is : it.second) {
                cout << is;
                --size > 0 ? cout << " " : cout << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end