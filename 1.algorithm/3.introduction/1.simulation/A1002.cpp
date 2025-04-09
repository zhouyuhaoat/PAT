/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 15:53:43
 *	modified:	2023-03-23 16:09:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805526272000000 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1002 A+B for Polynomials
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805526272000000
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    map<int, float, greater<int>> p;
    for (int i = 0; i < 2; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            float b;
            cin >> a >> b;
            p[a] += b;
            if (p[a] == 0) {
                p.erase(a);
            }
        }
    }
    cout << p.size();
    for (auto it : p) {
        cout << " " << it.first << " " << fixed << setprecision(1) << it.second;
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
