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
#include <map>
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
    map<string, int> sitec, sites; // count of testee, sum of scores of site
    map<string, map<string, int>> date; // site and count of testee of the site of date
    vector<pair<string, int>> card(n); // card number and score of testee
    for (int i = 0; i < n; i++) {
        cin >> card[i].first >> card[i].second;
        sitec[card[i].first.substr(1, 3)]++;
        sites[card[i].first.substr(1, 3)] += card[i].second;
        date[card[i].first.substr(4, 6)][card[i].first.substr(1, 3)]++;
    }
    sort(card.begin(), card.end(), cmp);
    for (int q = 0; q < m; q++) {
        int type;
        string term;
        cin >> type >> term;
        cout << "Case " << q + 1 << ": " << type << " " << term << "\n";
        bool isempty = true;
        if (type == 1) {
            for (auto it : card) {
                if (it.first[0] == term[0]) { // the level
                    cout << it.first << " " << it.second << "\n";
                    isempty = false;
                }
            }
        } else if (type == 2) {
            if (sitec[term] != 0) {
                cout << sitec[term] << " " << sites[term] << "\n";
                isempty = false;
            }
        } else {
            // map -> vector -> sort
            vector<pair<string, int>> ans(date[term].begin(), date[term].end());
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans) {
                cout << it.first << " " << it.second << "\n";
                isempty = false;
            }
        }
        if (isempty) {
            cout << "NA\n";
        }
    }

    return 0;
}
// @pintia code=end