/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 11:32:00
 *	modified:	2024-04-28 11:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805393241260032 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1075 PAT Judge
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805393241260032
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct stu {
    int id;
    int total;
    int rank;
    int perfect;
    bool show;
    vector<int> score;
    vector<bool> submit;
};

int main(int argc, char const *argv[]) {

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> p(k + 1);
    for (int i = 0; i < k; i++) {
        cin >> p[i + 1];
    }
    vector<stu> s(n + 1);
    for (int i = 0; i <= n; i++) {
        s[i].score.resize(k + 1);
        s[i].submit.resize(k + 1);
    }
    for (int i = 0; i < m; i++) {
        int id, num, score;
        cin >> id >> num >> score;
        s[id].id = id;
        if (score > s[id].score[num]) {
            s[id].total += score - s[id].score[num];
            s[id].score[num] = score;
            s[id].show = true;
            if (score == p[num]) {
                ++s[id].perfect;
            }
        } else if (score == 0) {
            s[id].show = true;
        }
        s[id].submit[num] = true;
    }
    sort(s.begin(), s.end(), [](stu a, stu b) -> bool {
        if (a.total != b.total) {
            return a.total > b.total;
        } else if (a.perfect != b.perfect) {
            return a.perfect > b.perfect;
        } else {
            return a.id < b.id;
        }
    });
    s[0].rank = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i].total == s[i - 1].total) {
            s[i].rank = s[i - 1].rank;
        } else {
            s[i].rank = i + 1;
        }
    }
    for (auto it : s) {
        if (it.show) {
            cout << it.rank << " " << setfill('0') << setw(5) << it.id << " " << it.total << " ";
            for (int i = 1; i <= k; i++) {
                if (it.submit[i]) {
                    cout << it.score[i];
                } else {
                    cout << "-";
                }
                if (i < k) {
                    cout << " ";
                } else {
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}
// @pintia code=end