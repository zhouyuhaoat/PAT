/*
 *	author:		zhouyuhao
 *	created:	2024-05-15 12:00:47
 *	modified:	2024-05-15 12:25:06
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805344776077312 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1139 First Contact
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344776077312
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1e4;

vector<vector<int>> g(maxn);
map<int, int> isfri;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int a = abs(stoi(s1)), b = abs(stoi(s2));
        if (s1.size() == s2.size()) { // same gender
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        // hashing manually: pair of numbers -> one number
        isfri[a * maxn + b] = isfri[b * maxn + a] = true;
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++) {
        int s1, s2;
        cin >> s1 >> s2;
        int a = abs(s1), b = abs(s2);
        vector<pair<int, int>> ans;
        // find all friends between two people by two loops
        for (int i = 0; i < (int)g[a].size(); i++) {
            for (int j = 0; j < (int)g[b].size(); j++) {
                if (g[a][i] == b || a == g[b][j]) { // repeated
                    continue;
                }
                if (isfri[g[a][i] * maxn + g[b][j]]) {
                    ans.emplace_back(make_pair(g[a][i], g[b][j]));
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto it : ans) {
            cout << setfill('0') << setw(4) << it.first << " " << setfill('0') << setw(4) << it.second << "\n";
        }
    }

    return 0;
}
// @pintia code=end