/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 16:30:41
 *	modified:	2023-03-27 10:12:49
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805383929905152 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1083 List Grades
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805383929905152
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct stu {
    string name, id;
    int grade;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<stu> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i].name >> list[i].id >> list[i].grade;
    }
    int lo, hi;
    cin >> lo >> hi;
    sort(list.begin(), list.end(), [](stu a, stu b) -> bool {
        return a.grade >= b.grade;
    });
    int cnt = 0;
    for (auto it : list) {
        if (it.grade >= lo && it.grade <= hi) {
            cout << it.name << " " << it.id << "\n";
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "NONE\n";
    }

    return 0;
}
// @pintia code=end
