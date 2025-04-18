/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 09:51:43
 *	modified:	2023-04-05 10:02:06
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1478634991737962496 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1157 Anniversary
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478634991737962496
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    map<string, bool> al; // alumni
    for (int i = 0; i < n; i++) {
        string id;
        cin >> id;
        al[id] = true;
    }
    int m;
    cin >> m;
    int cntal = 0;
    // oldest alumni, oldest guest, birth date
    string oal, oalbd = "99999999"; // birthday <=> string
    string ogu, ogubd = oalbd;
    for (int i = 0; i < m; i++) {
        string id;
        cin >> id;
        string bd = id.substr(6, 8);
        if (al[id]) {
            cntal++;
            if (bd < oalbd) {
                oalbd = bd;
                oal = id;
            }
        } else if (bd < ogubd) {
            ogubd = bd;
            ogu = id;
        }
    }
    cout << cntal << "\n";
    if (cntal == 0) {
        cout << ogu << "\n";
    } else {
        cout << oal << "\n";
    }

    return 0;
}
// @pintia code=end