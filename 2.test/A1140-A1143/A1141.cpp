/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 12:57:25
 *	modified:	2023-04-04 13:13:03
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805344222429184 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1141 PAT Ranking of Institutions
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344222429184
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Institution {
    int rank, score, number; // total score, number of testees
    string school;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<string, double> scores;
    unordered_map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string id, school;
        int score;
        cin >> id >> score >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if (id[0] == 'T') {
            scores[school] += score * 1.5;
        } else if (id[0] == 'B') {
            scores[school] += score / 1.5;
        } else {
            scores[school] += score;
        }
        cnt[school]++;
    }
    vector<Institution> res; // map -> vector
    for (auto [school, score] : scores) {
        res.emplace_back(Institution{1, (int)(score + 1e-8), cnt[school], school});
        /*
            1e-8
            - 1e-8 is a small number, which is used to avoid floating point error
            - in the case of 0.9999999999999999, it will be rounded to 1
            - and in the case of 1.0000000000000001, it will be rounded to 1
        */
    }
    sort(res.begin(), res.end(), [](Institution a, Institution b) {
        if (a.score != b.score) {
            return a.score > b.score;
        } else if (a.number != b.number) {
            return a.number < b.number;
        } else {
            return a.school < b.school;
        }
    });
    cout << res.size() << "\n";
    cout << res[0].rank << " " << res[0].school << " " << res[0].score << " " << res[0].number << "\n";
    for (int i = 1; i < (int)res.size(); i++) {
        if (res[i].score == res[i - 1].score) {
            res[i].rank = res[i - 1].rank;
        } else {
            res[i].rank = i + 1;
        }
        cout << res[i].rank << " " << res[i].school << " " << res[i].score << " " << res[i].number << "\n";
    }

    return 0;
}
// @pintia code=end
