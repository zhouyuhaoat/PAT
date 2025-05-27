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

struct Student {
    string id;
    int program, mid, final, grade;
    Student() : program(-1), mid(-1), final(-1), grade(-1) { // -1: not present
    }
};

int main(int argc, char const *argv[]) {

    int p, m, n;
    cin >> p >> m >> n;
    unordered_map<string, Student> students; // id -> student
    for (int i = 0; i < p + m + n; i++) {
        string id;
        int score;
        cin >> id >> score;
        students[id].id = id;
        if (i < p) {
            students[id].program = score;
        } else if (i < p + m) {
            students[id].mid = score;
        } else {
            students[id].final = score;
        }
    }
    vector<Student> res;
    for (auto [id, student] : students) {
        if (student.final != -1) {
            if (student.mid != -1 && student.mid > student.final) {
                student.grade = 0.4 * student.mid + 0.6 * student.final + 0.5;
            } else {
                student.grade = student.final;
            }
        }
        if (student.program >= 200 && student.grade >= 60) {
            res.emplace_back(student);
        }
    }
    sort(res.begin(), res.end(), [](Student a, Student b) {
        if (a.grade != b.grade) {
            return a.grade > b.grade;
        } else {
            return a.id < b.id;
        }
    });
    for (auto [id, program, mid, final, grade] : res) {
        cout << id << " " << program << " " << mid << " " << final << " " << grade << "\n";
    }

    return 0;
}
// @pintia code=end
