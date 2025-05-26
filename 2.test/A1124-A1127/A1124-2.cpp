/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:45:36
 *	modified:	2023-04-03 02:54:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805350803292160 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1124 Raffle for Weibo Followers
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805350803292160
*/

// @pintia code=start
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int m, n, first;
    cin >> m >> n >> first;
    unordered_map<string, bool> win;
    int cnt = 0; // count of followers from the first winner, except won before
    for (int i = 1; i <= m; i++) { // online
        string name;
        cin >> name;
        if (i < first) continue; // not started yet
        if (cnt++ % n == 0) { // cnt % gap == 0 to get current winner
            if (win[name]) {
                cnt--; // won before, disregard, and restore cnt
                continue;
            }
            win[name] = true;
            cout << name << "\n";
        }
    }
    if (first > m) {
        cout << "Keep going...\n";
    }

    return 0;
}
// @pintia code=end
