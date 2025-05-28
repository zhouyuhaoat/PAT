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
    unordered_map<string, bool> alumni;
    for (int i = 0; i < n; i++) {
        string id;
        cin >> id;
        alumni[id] = true;
    }
    int m;
    cin >> m;
    int cnt = 0; // count of alumni
    pair<string, string> oldAlumni, oldGuest; // {id, date}
    oldAlumni.second = "99999999", oldGuest.second = oldAlumni.second;
    for (int i = 0; i < m; i++) {
        string id;
        cin >> id;
        string date = id.substr(6, 8);
        if (alumni[id]) {
            cnt++;
            if (date < oldAlumni.second) {
                oldAlumni = {id, date};
            }
        } else if (date < oldGuest.second) {
            oldGuest = {id, date};
        }
    }
    cout << cnt << "\n";
    cnt == 0 ? cout << oldGuest.first << "\n" : cout << oldAlumni.first << "\n";

    return 0;
}
// @pintia code=end
