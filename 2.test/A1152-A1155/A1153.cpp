/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 19:59:56
 *	modified:	2023-04-04 20:46:20
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=1071785190929788928 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1153 Decode Registration Card of PAT
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785190929788928
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    unordered_map<string, int> cnt, score; // site -> count of testee, sum of scores
    unordered_map<string, unordered_map<string, int>> date; // data -> site -> count of testee
    vector<pair<string, int>> card(n); // {id, score of testee}
    for (int i = 0; i < n; i++) {
        cin >> card[i].first >> card[i].second;
        cnt[card[i].first.substr(1, 3)]++;
        score[card[i].first.substr(1, 3)] += card[i].second;
        date[card[i].first.substr(4, 6)][card[i].first.substr(1, 3)]++;
    }
    sort(card.begin(), card.end(), cmp);
    for (int q = 0; q < m; q++) {
        int type;
        string term;
        cin >> type >> term;
        cout << "Case " << q + 1 << ": " << type << " " << term << "\n";
        bool flag = true;
        if (type == 1) {
            for (auto [id, score] : card) {
                if (id[0] == term[0]) { // the level
                    cout << id << " " << score << "\n";
                    flag = false;
                }
            }
        } else if (type == 2) {
            if (cnt[term] != 0) {
                cout << cnt[term] << " " << score[term] << "\n";
                flag = false;
            }
        } else {
            vector<pair<string, int>> res(date[term].begin(), date[term].end());
            sort(res.begin(), res.end(), cmp);
            for (auto [site, cnt] : res) {
                cout << site << " " << cnt << "\n";
                flag = false;
            }
        }
        if (flag) {
            cout << "NA\n";
        }
    }

    return 0;
}
// @pintia code=end
