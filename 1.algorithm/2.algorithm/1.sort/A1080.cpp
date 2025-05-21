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

struct Student {
    int id;
    int exam, interview, grade;
    int rank;
    vector<int> choice;
};

struct School {
    set<int> admit;
    int last; // last admitted rank
};

int main(int argc, char const *argv[]) {

    int n, m, k;
    cin >> n >> m >> k; // applicants, schools, choices
    vector<int> quota(m);
    for (int i = 0; i < m; i++) {
        cin >> quota[i];
    }
    vector<Student> student(n);
    for (int i = 0; i < n; i++) {
        student[i].id = i;
        cin >> student[i].exam >> student[i].interview;
        student[i].grade = student[i].exam + student[i].interview;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            student[i].choice.emplace_back(c);
        }
    }
    sort(student.begin(), student.end(), [](Student a, Student b) {
        if (a.grade != b.grade) {
            return a.grade > b.grade;
        } else {
            return a.exam > b.exam;
        }
    });
    student[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if ((student[i].grade == student[i - 1].grade) && (student[i].exam == student[i - 1].exam)) {
            student[i].rank = student[i - 1].rank;
        } else {
            student[i].rank = i + 1;
        }
    }
    vector<School> school(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int id = student[i].choice[j];
            if (quota[id] > 0) {
                school[id].admit.emplace(student[i].id);
                school[id].last = student[i].rank;
                quota[id]--;
                break;
            } else if (quota[id] == 0 && school[id].last == student[i].rank) { // tied rank
                school[id].admit.emplace(student[i].id); // even exceed the quota
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto it = school[i].admit.begin(); it != school[i].admit.end(); it++) {
            cout << *it;
            next(it) != school[i].admit.end() ? cout << " " : cout << "";
        }
        cout << "\n"; // empty line if no one is admitted
    }

    return 0;
}
// @pintia code=end
