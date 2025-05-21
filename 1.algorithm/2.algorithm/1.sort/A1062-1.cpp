/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 13:05:34
 *	modified:	2023-03-23 13:26:51
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    int type; // flag
};

int main(int argc, char const *argv[]) {

    int n, lo, hi;
    cin >> n >> lo >> hi;
    vector<People> people;
    for (int i = 0; i < n; i++) {
        People p;
        cin >> p.id >> p.virtue >> p.talent;
        p.total = p.virtue + p.talent;
        if (p.virtue < lo || p.talent < lo) {
            continue;
        } else if (p.virtue >= hi && p.talent >= hi) {
            p.type = 1;
        } else if (p.virtue >= hi && p.talent < hi) {
            p.type = 2;
        } else if (p.virtue < hi && p.talent < hi && p.virtue >= p.talent) {
            p.type = 3;
        } else {
            p.type = 4;
        }
        people.emplace_back(p);
    }
    sort(people.begin(), people.end(), [](People a, People b) {
        if (a.type != b.type) {
            return a.type < b.type;
        } else if (a.total != b.total) {
            return a.total > b.total;
        } else if (a.virtue != b.virtue) {
            return a.virtue > b.virtue;
        } else {
            return a.id < b.id;
        }
    });
    cout << people.size() << "\n";
    for (auto it : people) {
        cout << it.id << " " << it.virtue << " " << it.talent << "\n";
    }

    return 0;
}
// @pintia code=end
