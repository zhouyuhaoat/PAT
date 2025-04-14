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

struct stu {
    string id;
    int score, fr, loc, lr;
};

bool cmp(stu a, stu b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return a.id < b.id;
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<stu> list;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            stu s;
            cin >> s.id >> s.score;
            s.loc = i + 1;
            list.emplace_back(s);
        }
        sort(list.begin() + cnt, list.begin() + cnt + k, cmp);
        list[cnt].lr = 1;
        for (int j = cnt + 1; j < cnt + k; j++) {
            if (list[j].score == list[j - 1].score) {
                list[j].lr = list[j - 1].lr;
            } else {
                list[j].lr = j - cnt + 1;
            }
        }
        cnt += k;
    }
    sort(list.begin(), list.end(), cmp);
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        if (i > 0 && list[i].score == list[i - 1].score) {
            list[i].fr = list[i - 1].fr;
        } else {
            list[i].fr = i + 1;
        }
        cout << list[i].id << " " << list[i].fr << " " << list[i].loc << " " << list[i].lr << "\n";
    }

    return 0;
}
// @pintia code=end
