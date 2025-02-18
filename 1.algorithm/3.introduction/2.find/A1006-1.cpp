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
    string firstid, lastid;
    int firsts = 24 * 3600 + 1, lasts = -1;
    for (int i = 0; i < m; ++i) {
        string id;
        cin >> id;
        int h, m, s;
        int unused __attribute__((unused));
        unused = scanf("%d:%d:%d", &h, &m, &s);
        int ins = h * 3600 + m * 60 + s;
        unused = scanf("%d:%d:%d", &h, &m, &s);
        int outs = h * 3600 + m * 60 + s;
        if (ins < firsts) {
            firsts = ins;
            firstid = id;
        }
        if (outs > lasts) {
            lasts = outs;
            lastid = id;
        }
    }
    cout << firstid << " " << lastid << "\n";

    return 0;
}
// @pintia code=end