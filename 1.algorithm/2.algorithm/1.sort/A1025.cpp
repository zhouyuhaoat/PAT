/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:58:47
 *	modified:	2023-03-22 12:37:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805474338127872 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1025 PAT Ranking
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805474338127872
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string id;
    int score, loc; // location
    int final, local; // rank: final, local
};

bool cmp(Student a, Student b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return a.id < b.id;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<Student> student;
    for (int i = 0, lo = 0, hi = 0; i < n; i++, lo = hi) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            Student s;
            cin >> s.id >> s.score;
            s.loc = i + 1;
            student.emplace_back(s);
        }
        sort(student.begin() + lo, student.begin() + (hi = lo + k), cmp); // sort in a local part
        student[lo].local = 1;
        for (int j = lo + 1; j < hi; j++) {
            if (student[j].score == student[j - 1].score) {
                student[j].local = student[j - 1].local;
            } else {
                student[j].local = j - lo + 1;
            }
        }
    }
    sort(student.begin(), student.end(), cmp); // sort in the global part
    cout << student.size() << "\n";
    for (int i = 0; i < (int)student.size(); i++) {
        if (i > 0 && student[i].score == student[i - 1].score) {
            student[i].final = student[i - 1].final;
        } else { // i == 0 || student[i].score != student[i - 1].score
            student[i].final = i + 1;
        }
        cout << student[i].id << " " << student[i].final << " " << student[i].loc << " " << student[i].local << "\n";
    }

    return 0;
}
// @pintia code=end
