/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 21:16:00
 *	modified:	2024-04-27 21:20:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805410555346944 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1062 Talent and Virtue
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805410555346944
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct People {
    int id;
    int virtue, talent, total;
};

int main(int argc, char const *argv[]) {

    int n, lo, hi;
    cin >> n >> lo >> hi;
    vector<People> people[4]; // buckets
    int cnt = n;
    for (int i = 0; i < n; i++) {
        People p;
        cin >> p.id >> p.virtue >> p.talent;
        p.total = p.virtue + p.talent;
        if (p.virtue < lo || p.talent < lo) {
            cnt--;
            continue;
        } else if (p.virtue >= hi && p.talent >= hi) {
            people[0].emplace_back(p);
        } else if (p.virtue >= hi && p.talent < hi) {
            people[1].emplace_back(p);
        } else if (p.virtue < hi && p.talent < hi && p.virtue >= p.talent) {
            people[2].emplace_back(p);
        } else {
            people[3].emplace_back(p);
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < 4; i++) {
        sort(people[i].begin(), people[i].end(), [](People a, People b) {
            if (a.total != b.total) {
                return a.total > b.total;
            } else if (a.virtue != b.virtue) {
                return a.virtue > b.virtue;
            } else {
                return a.id < b.id;
            }
        });
        for (auto it : people[i]) {
            cout << it.id << " " << it.virtue << " " << it.talent << "\n";
        }
    }

    return 0;
}
// @pintia code=end
