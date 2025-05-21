/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 13:29:01
 *	modified:	2023-03-24 19:58:17
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805502658068480 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1012 The Best Rank
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805502658068480
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Student {
    int id, score[4], rank[4]; // priority: Average, C, Math, English
    int best = 0; // the index of the best subject
};

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<Student> student(n);
    for (int i = 0; i < n; i++) {
        cin >> student[i].id;
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            cin >> student[i].score[j + 1];
            sum += student[i].score[j + 1];
        }
        student[i].score[0] = sum / 3 + 0.5;
    }
    for (int i = 0; i < 4; i++) {
        sort(student.begin(), student.end(), [i](Student a, Student b) {
            return a.score[i] > b.score[i];
        });
        student[0].rank[i] = 1;
        for (int j = 0; j < n; j++) {
            if (j > 0 && student[j].score[i] == student[j - 1].score[i]) {
                student[j].rank[i] = student[j - 1].rank[i];
            } else {
                student[j].rank[i] = j + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        student[i].best = min_element(student[i].rank, student[i].rank + 4) - student[i].rank;
    }
    unordered_map<int, Student> query;
    for (auto it : student) {
        query.emplace(it.id, it);
    }
    string subject = "ACME";
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        if (query.find(id) == query.end()) {
            cout << "N/A\n";
        } else {
            cout << query[id].rank[query[id].best] << " " << subject[query[id].best] << "\n";
        }
    }

    return 0;
}
// @pintia code=end
