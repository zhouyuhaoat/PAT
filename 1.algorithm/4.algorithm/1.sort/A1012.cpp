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

struct stu {
    int id, score[4], rank[4]; // priorities: Average, C, Math, English
    int best; // the best index
};

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<stu> data(n); // data of students
    for (int i = 0; i < n; i++) {
        cin >> data[i].id;
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            cin >> data[i].score[j + 1];
            sum += data[i].score[j + 1];
        }
        data[i].score[0] = sum / 3 + 0.5;
    }
    for (int i = 0; i < 4; i++) {
        sort(data.begin(), data.end(), [i](stu a, stu b) -> bool {
            return a.score[i] > b.score[i];
        });
        data[0].rank[i] = 1;
        for (int j = 1; j < n; j++) {
            if (data[j].score[i] == data[j - 1].score[i]) {
                data[j].rank[i] = data[j - 1].rank[i];
            } else {
                data[j].rank[i] = j + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        data[i].best = min_element(data[i].rank, data[i].rank + 4) - data[i].rank;
    }
    unordered_map<int, stu> query;
    for (auto it : data) {
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
