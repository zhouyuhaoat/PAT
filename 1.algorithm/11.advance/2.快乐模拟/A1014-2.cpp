/*
 *	author:		zhouyuhao
 *	created:	2023-04-12 23:42:25
 *	modified:	2023-04-13 08:50:22
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805498207911936 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1014 Waiting in Line
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805498207911936
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<queue<int>> windows(n + 1);
    vector<int> processTime(k + 1), endTime(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> processTime[i];
        int windowID = 1;
        if (i <= m * n) { // before full, find the window with fewer customers
            for (int j = 1; j <= n; j++) { // find the window with fewer customers
                if (windows[j].size() < windows[windowID].size()) {
                    windowID = j;
                }
            }
        } else { // after full, find the window with the earliest end time
            for (int j = 1; j <= n; j++) {
                if (windows[j].front() < windows[windowID].front()) {
                    windowID = j;
                }
            }
        }
        endTime[i] = (windows[windowID].empty() ? 0 : windows[windowID].back()) + processTime[i];
        if ((int)windows[windowID].size() >= m) { // full
            windows[windowID].pop();
        }
        windows[windowID].emplace(endTime[i]);
    }
    while (q--) {
        int id;
        cin >> id;
        if (endTime[id] - processTime[id] >= 540) {
            cout << "Sorry\n";
        } else {
            cout << setfill('0') << setw(2) << 8 + endTime[id] / 60 << ":";
            cout << setfill('0') << setw(2) << endTime[id] % 60 << "\n";
        }
    }

    return 0;
}
// @pintia code=end
