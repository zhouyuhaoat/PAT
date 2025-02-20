/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 21:36:09
 *	modified:	2023-03-26 22:07:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805447855292416 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1039 Course List for Student
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805447855292416
*/

// @pintia code=start
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    map<string, set<int>> c;
    for (int i = 0; i < k; i++) {
        int no, ns;
        cin >> no >> ns;
        for (int j = 0; j < ns; j++) {
            string name;
            cin >> name;
            c[name].emplace(no);
        }
    }
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cout << name << " " << c[name].size();
        for (auto it : c[name]) {
            cout << " " << it;
        }
        cout << "\n";
    }

    return 0;
}
// @pintia code=end