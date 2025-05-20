/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 15:35:00
 *	modified:	2024-04-27 15:40:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805516654460928 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1006 Sign In and Sign Out
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805516654460928
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int m;
    cin >> m;
    pair<string, string> first, last;
    first.second = "24:00:01", last.second = "00:00:00"; // compare string of time directly
    for (int i = 0; i < m; i++) {
        string id, in, out;
        cin >> id >> in >> out;
        if (in < first.second) {
            first = {id, in};
        }
        if (out >= last.second) {
            last = {id, out};
        }
    }
    cout << first.first << " " << last.first << "\n";

    return 0;
}
// @pintia code=end
