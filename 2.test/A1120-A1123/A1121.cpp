/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 01:56:12
 *	modified:	2023-04-03 02:12:12
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805352359378944 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1121 Damn Single
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805352359378944
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    unordered_map<string, string> couple; // int -> string: avoid id = 00000
    for (int i = 0; i < n; i++) {
        string c1, c2;
        cin >> c1 >> c2;
        couple[c1] = c2, couple[c2] = c1;
    }
    int m;
    cin >> m;
    unordered_map<string, bool> guest;
    set<string> single; // damn single
    for (int i = 0; i < m; i++) {
        string id;
        cin >> id;
        if (guest[couple[id]]) { // couple is guested before
            single.erase(couple[id]);
        } else {
            single.emplace(id);
        }
        guest[id] = true;
    }
    cout << single.size() << "\n";
    for (auto it = single.begin(); it != single.end(); it++) {
        cout << *it;
        next(it) != single.end() ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
