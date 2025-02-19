/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 20:41:09
 *	modified:	2023-03-25 20:57:13
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805260223102976 pid=994805292322111488 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1029 旧键盘
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805292322111488
*/

// @pintia code=start
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {

    string a, b;
    cin >> a >> b;
    set<char> r;
    for (int i = 0; i < (int)a.size(); i++) {
        if (b.find(a[i]) == string::npos) {
            a[i] = toupper(a[i]);
            if (r.find(a[i]) == r.end()) {
                r.emplace(a[i]);
                cout << a[i];
            }
        }
    }
    cout << "\n";

    return 0;
}
// @pintia code=end