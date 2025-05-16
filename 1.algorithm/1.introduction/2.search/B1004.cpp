/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:37:50
 *	modified:	2023-03-22 19:41:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805321640296448 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1004 成绩排名
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805321640296448
*/

// @pintia code=start
#include <iostream>

using namespace std;

struct Student {
    int grade;
    string name, id;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Student hi = {-1}, lo = {101}; // highest, lowest
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.name >> s.id >> s.grade;
        if (s.grade > hi.grade) {
            hi = s;
        }
        if (s.grade < lo.grade) {
            lo = s;
        }
    }
    cout << hi.name << " " << hi.id << "\n";
    cout << lo.name << " " << lo.id << "\n";

    return 0;
}
// @pintia code=end
