/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:19:55
 *	modified:	2023-03-23 15:50:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805313708867584 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1010 一元多项式求导
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805313708867584
*/

// @pintia code=start
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

    map<int, int, greater<int>> p;
    int a, b;
    while (cin >> a >> b) {
        if (b != 0) {
            p.insert(make_pair(b - 1, a * b));
        }
    }
    if (p.empty()) {
        cout << "0 0\n";
    } else {
        bool first = true;
        for (auto it : p) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << it.second << " " << it.first;
        }
        cout << "\n";
    }

    return 0;
}
// @pintia code=end
