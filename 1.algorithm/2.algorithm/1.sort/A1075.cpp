/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 11:32:00
 *	modified:	2024-04-28 11:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805393241260032 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1075 PAT Judge
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805393241260032
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id = 0, grade = 0, rank = 0, perfect = 0;
    bool show = false;
    vector<int> score;
    vector<bool> submit;
    Student(int n = 0) : score(n + 1), submit(n + 1) {
    }
};

int main(int argc, char const *argv[]) {

    int n, k, m;
    cin >> n >> k >> m; // users, problems, submissions
    vector<int> full(k + 1); // full score of each problem
    for (int i = 0; i < k; i++) {
        cin >> full[i + 1];
    }
    vector<Student> student(n + 1, Student(k));
    for (int i = 0; i < m; i++) {
        int user, id, score;
        cin >> user >> id >> score;
        student[user].id = user;
        if (score > student[user].score[id]) { // higher score
            student[user].grade += score - student[user].score[id];
            student[user].score[id] = score;
            if (score == full[id]) { // perfectly solved
                student[user].perfect++;
            }
        }
        if (score >= 0) { // show if submit and pass the compiler
            student[user].show = true;
        }
        student[user].submit[id] = true; // submitted this problem
    }
    sort(student.begin(), student.end(), [](Student a, Student b) {
        if (a.grade != b.grade) {
            return a.grade > b.grade;
        } else if (a.perfect != b.perfect) {
            return a.perfect > b.perfect;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0; i < (int)student.size(); i++) {
        if (i > 0 && student[i].grade == student[i - 1].grade) {
            student[i].rank = student[i - 1].rank;
        } else {
            student[i].rank = i + 1;
        }
        if (!student[i].show) {
            continue;
        }
        cout << student[i].rank << " " << setfill('0') << setw(5) << student[i].id << " " << student[i].grade << " ";
        for (int j = 1; j <= k; j++) {
            student[i].submit[j] ? cout << student[i].score[j] : cout << "-";
            j < k ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
