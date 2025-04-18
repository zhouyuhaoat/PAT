/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 16:38:45
 *	modified:	2023-03-31 15:36:24
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805387268571136 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1080 Graduate Admission
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805387268571136
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct stu {
    int id;
    int ge, gi, fg;
    int rank;
    vector<int> choice;
};

struct sch {
    set<int> admit;
    int lastAdminRank;
};

int main(int argc, char const *argv[]) {

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> quota(m);
    for (int i = 0; i < m; i++) {
        cin >> quota[i];
    }
    vector<stu> s(n);
    for (int i = 0; i < n; i++) {
        s[i].id = i;
        cin >> s[i].ge >> s[i].gi;
        s[i].fg = s[i].ge + s[i].gi;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            s[i].choice.emplace_back(c);
        }
    }
    sort(s.begin(), s.end(), [](stu a, stu b) -> bool {
        if (a.fg != b.fg) {
            return a.fg > b.fg;
        } else {
            return a.ge > b.ge;
        }
    });
    s[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if ((s[i].fg == s[i - 1].fg) && (s[i].ge == s[i - 1].ge)) {
            s[i].rank = s[i - 1].rank;
        } else {
            s[i].rank = i + 1;
        }
    }
    vector<sch> school(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int no = s[i].choice[j];
            if (quota[no] > 0) {
                school[no].admit.emplace(s[i].id);
                school[no].lastAdminRank = s[i].rank;
                quota[no]--;
                break;
            } else if (quota[no] == 0 && school[no].lastAdminRank == s[i].rank) { // tied rank
                school[no].admit.emplace(s[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (auto it : school[i].admit) {
            cout << it;
            if (++cnt < (int)school[i].admit.size()) cout << " ";
        }
        cout << "\n"; // empty line if no one is admitted
    }

    return 0;
}
// @pintia code=end
