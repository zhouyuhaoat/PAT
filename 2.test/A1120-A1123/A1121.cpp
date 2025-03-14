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
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    map<int, int> c; // couple
    for (int i = 0; i < n; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        c[c1] = c2, c[c2] = c1;
    }
    int m;
    cin >> m;
    map<int, bool> g; // guest
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        g[d[i]] = true;
    }
    set<int> single; // damn single
    for (int i = 0; i < m; i++) {
        if (!g[c[d[i]]]) { // if not couple
            single.emplace(d[i]);
        }
    }
    int size = single.size();
    cout << size << "\n";
    for (auto it : single) {
        cout << setfill('0') << setw(5) << it;
        --size > 0 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end