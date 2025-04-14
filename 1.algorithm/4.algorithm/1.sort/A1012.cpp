/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 13:29:01
 *	modified:	2023-03-24 19:58:17
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805502658068480 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1012 The Best Rank
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805502658068480
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct stu {
    int id, s[4], r[4], rank;
    char subject;
};

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<stu> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].id;
        double avg = 0;
        for (int j = 0; j < 3; j++) {
            cin >> d[i].s[j + 1];
            avg += d[i].s[j + 1];
        }
        d[i].s[0] = avg / 3 + 0.5;
    }
    for (int i = 0; i < 4; i++) {
        sort(d.begin(), d.end(), [i](stu a, stu b) -> bool {
            return a.s[i] > b.s[i];
        });
        d[0].r[i] = 1;
        for (int j = 1; j < n; j++) {
            if (d[j].s[i] == d[j - 1].s[i]) {
                d[j].r[i] = d[j - 1].r[i];
            } else {
                d[j].r[i] = j + 1;
            }
        }
    }
    const string subject = "ACME";
    for (int i = 0; i < n; i++) {
        int j = min_element(d[i].r, d[i].r + 4) - d[i].r;
        d[i].rank = d[i].r[j];
        d[i].subject = subject[j];
    }
    unordered_map<int, stu> q;
    for (auto it : d) {
        q.emplace(make_pair(it.id, it));
    }
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        if (q.find(id) == q.end()) {
            cout << "N/A\n";
        } else {
            cout << q[id].rank << " " << q[id].subject << "\n";
        }
    }

    return 0;
}
// @pintia code=end
