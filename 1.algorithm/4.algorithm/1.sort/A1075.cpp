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

struct stu {
    int id, total, rank, perfect;
    bool show;
    vector<int> score;
    vector<bool> submit;
};

int main(int argc, char const *argv[]) {

    int n, k, m;
    cin >> n >> k >> m; // users, problems, submissions
    vector<int> prob(k + 1); // full score of each problem
    for (int i = 0; i < k; i++) {
        cin >> prob[i + 1];
    }
    vector<stu> list(n + 1);
    for (int i = 0; i <= n; i++) {
        list[i].score.resize(k + 1), list[i].submit.resize(k + 1);
    }
    for (int i = 0; i < m; i++) {
        int user, id, score;
        cin >> user >> id >> score;
        list[user].id = user;
        if (score > list[user].score[id]) { // higher score
            list[user].total += score - list[user].score[id];
            list[user].score[id] = score;
            if (score == prob[id]) { // perfectly solved
                list[user].perfect++;
            }
        }
        if (score >= 0) list[user].show = true; // show if submit and pass the compiler
        list[user].submit[id] = true;
    }
    sort(list.begin(), list.end(), [](stu a, stu b) -> bool {
        if (a.total != b.total) {
            return a.total > b.total;
        } else if (a.perfect != b.perfect) {
            return a.perfect > b.perfect;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0; i < (int)list.size(); i++) {
        if (i > 0 && list[i].total == list[i - 1].total) {
            list[i].rank = list[i - 1].rank;
        } else {
            list[i].rank = i + 1;
        }
        if (list[i].show) {
            cout << list[i].rank << " " << setfill('0') << setw(5) << list[i].id << " " << list[i].total << " ";
            for (int j = 1; j <= k; j++) {
                list[i].submit[j] ? cout << list[i].score[j] : cout << "-";
                j < k ? cout << " " : cout << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end
