/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 12:57:25
 *	modified:	2023-04-04 13:13:03
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805344222429184 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1141 PAT Ranking of Institutions
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344222429184
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ins { // institution
    int r, t, n; // rank, total score, number of testees
    string id;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<string, double> insSco; // score
    unordered_map<string, int> insCnt; // count
    for (int i = 0; i < n; i++) {
        string id, sch;
        int sco;
        cin >> id >> sco >> sch;
        transform(sch.begin(), sch.end(), sch.begin(), ::tolower);
        if (id[0] == 'T') {
            insSco[sch] += sco * 1.5;
        } else if (id[0] == 'B') {
            insSco[sch] += sco / 1.5;
        } else {
            insSco[sch] += sco;
        }
        insCnt[sch]++;
    }
    vector<ins> ans; // map to vector
    for (auto it : insSco) {
        ans.emplace_back(ins{1, (int)(it.second + 1e-8), insCnt[it.first], it.first});
        // 1e-8 is a small number, which is used to avoid floating point error
        // in the case of 0.9999999999999999, it will be rounded to 1
        // and in the case of 1.0000000000000001, it will be rounded to 1
    }
    sort(ans.begin(), ans.end(), [](ins a, ins b) {
        if (a.t != b.t) {
            return a.t > b.t;
        } else if (a.n != b.n) {
            return a.n < b.n;
        } else {
            return a.id < b.id;
        }
    });
    cout << ans.size() << "\n";
    cout << ans[0].r << " " << ans[0].id << " " << ans[0].t << " " << ans[0].n << "\n";
    for (int i = 1; i < (int)ans.size(); i++) { // rank
        if (ans[i].t == ans[i - 1].t) {
            ans[i].r = ans[i - 1].r;
        } else {
            ans[i].r = i + 1;
        }
        cout << ans[i].r << " " << ans[i].id << " " << ans[i].t << " " << ans[i].n << "\n";
    }

    return 0;
}
// @pintia code=end
