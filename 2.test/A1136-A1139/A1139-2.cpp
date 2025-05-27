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
#include <unordered_map>
#include <vector>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first << 16) | p.second);
    }
};

unordered_map<int, vector<int>> g;
unordered_map<pair<int, int>, bool, PairHash> isFriend;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int id1 = abs(stoi(s1)), id2 = abs(stoi(s2));
        if (s1.size() == s2.size()) {
            g[id1].emplace_back(id2), g[id2].emplace_back(id1);
        }
        isFriend[{id1, id2}] = isFriend[{id2, id1}] = true;
    }
    int k;
    cin >> k;
    while (k--) {
        int s1, s2;
        cin >> s1 >> s2;
        int id1 = abs(s1), id2 = abs(s2);
        vector<pair<int, int>> res;
        for (int u : g[id1]) {
            for (int v : g[id2]) {
                if (u == id2 || v == id1) continue;
                if (isFriend[{u, v}]) {
                    res.emplace_back(u, v);
                }
            }
        }
        sort(res.begin(), res.end());
        cout << res.size() << "\n";
        for (auto [id1, id2] : res) {
            cout << setfill('0') << setw(4) << id1 << " " << setfill('0') << setw(4) << id2 << "\n";
        }
    }

    return 0;
}
// @pintia code=end
