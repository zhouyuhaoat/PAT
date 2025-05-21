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

struct Student {
    string name, id;
    int grade;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<Student> student(n);
    for (int i = 0; i < n; i++) {
        cin >> student[i].name >> student[i].id >> student[i].grade;
    }
    sort(student.begin(), student.end(), [](Student a, Student b) {
        return a.grade >= b.grade;
    });
    int lo, hi, cnt = 0;
    cin >> lo >> hi;
    for (auto it : student) {
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
