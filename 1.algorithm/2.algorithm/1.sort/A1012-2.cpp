/*
 *	author:		zhouyuhao
 *	created:	2025-05-16 13:29:01
 *	modified:	2025-05-16 19:58:17
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
    int id, score[4], rank[4];
    int best = 0;
};

void update(Student& s, int subject) { // update the best subject
    if (s.rank[subject] < s.rank[s.best]) {
        s.best = subject;
    }
}

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
        for (int j = 0; j < n; j++) {
            if (j > 0 && student[j].score[i] == student[j - 1].score[i]) {
                student[j].rank[i] = student[j - 1].rank[i];
            } else { // j == 0 || student[j].score[i] != student[j - 1].score[i]
                student[j].rank[i] = j + 1;
            }
            update(student[j], i);
        }
    }
    string subject = "ACME";
    unordered_map<int, pair<int, char>> query; // id -> {rank, subject}
    for (auto it : student) {
        query[it.id] = {it.rank[it.best], subject[it.best]};
    }
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        if (query.find(id) == query.end()) {
            cout << "N/A\n";
        } else {
            cout << query[id].first << " " << query[id].second << "\n";
        }
    }

    return 0;
}
// @pintia code=end
