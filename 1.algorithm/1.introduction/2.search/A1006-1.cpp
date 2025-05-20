/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 20:40:55
 *	modified:	2023-03-22 20:50:36
 *	item:		Programming Ability Test
 *	site:		Yuting
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
    pair<string, int> first = {"", 24 * 3600 + 1}, last = {"", -1}; // {id, time}
    for (int i = 0; i < m; i++) {
        string id;
        cin >> id;
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int in = hh * 3600 + mm * 60 + ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int out = hh * 3600 + mm * 60 + ss;
        if (in < first.second) {
            first = {id, in};
        }
        if (out > last.second) {
            last = {id, out};
        }
    }
    cout << first.first << " " << last.first << "\n";

    return 0;
}
// @pintia code=end
