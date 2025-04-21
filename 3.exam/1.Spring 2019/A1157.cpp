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
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<string, bool> alum; // alumni
    for (int i = 0; i < n; i++) {
        string id;
        cin >> id;
        alum[id] = true;
    }
    int m;
    cin >> m;
    int cntAlum = 0;
    // oldest, alumni, guest: {ID, date}
    pair<string, string> oldAlum = {"", "99999999"}, oldGst = oldAlum;
    for (int i = 0; i < m; i++) {
        string id;
        cin >> id;
        string day = id.substr(6, 8);
        if (alum[id]) {
            cntAlum++;
            if (day < oldAlum.second) {
                oldAlum = {id, day};
            }
        } else if (day < oldGst.second) {
            oldGst = {id, day};
        }
    }
    cout << cntAlum << "\n";
    cntAlum == 0 ? cout << oldGst.first << "\n" : cout << oldAlum.first << "\n";

    return 0;
}
// @pintia code=end
