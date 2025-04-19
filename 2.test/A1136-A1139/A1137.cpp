/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 12:41:21
 *	modified:	2023-04-04 09:46:29
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805345401028608 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1137 Final Grading
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345401028608
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct stu {
    string id;
    int gp, gm, gf, g;
    // p: programming, m: mid-term, f: final, g: grade
    stu() : gp(-1), gm(-1), gf(-1), g(-1) { // -1: not present
    }
};

int main(int argc, char const *argv[]) {

    int p, m, n;
    cin >> p >> m >> n;
    unordered_map<string, stu> students;
    for (int i = 0; i < p + m + n; i++) {
        string id;
        int v;
        cin >> id >> v;
        students[id].id = id;
        if (i < p) {
            students[id].gp = v;
        } else if (i < p + m) {
            students[id].gm = v;
        } else {
            students[id].gf = v;
        }
    }
    vector<stu> ans;
    for (auto& it : students) {
        stu& s = it.second;
        if (s.gf != -1) {
            if (s.gm != -1 && s.gm > s.gf) {
                s.g = 0.4 * s.gm + 0.6 * s.gf + 0.5;
            } else {
                s.g = s.gf;
            }
        }
        if (s.gp >= 200 && s.g >= 60) {
            ans.emplace_back(s);
        }
    }
    sort(ans.begin(), ans.end(), [](stu& a, stu& b) {
        if (a.g != b.g) {
            return a.g > b.g;
        } else {
            return a.id < b.id;
        }
    });
    for (auto& s : ans) {
        cout << s.id << " " << s.gp << " " << s.gm << " " << s.gf << " " << s.g << "\n";
    }

    return 0;
}
// @pintia code=end
