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
    if (first > m) {
        cout << "Keep going...\n";
        return 0;
    }
    unordered_map<string, bool> win;
    int id = first; // index of winner
    for (int i = 1; i <= m; i++) {
        string name;
        cin >> name;
        if (i == id) { // i == id to get current winner
            if (win[name]) {
                id++;
            } else {
                win[name] = true;
                cout << name << "\n";
                id += n;
            }
        }
    }

    return 0;
}
// @pintia code=end
