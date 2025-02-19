/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:02:10
 *	modified:	2023-03-25 21:18:51
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805260223102976 pid=994805288530460672 compiler=GXX
  ProblemSet: PAT (Basic Level) Practice （中文）
  Title: 1033 旧键盘打字
  https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805288530460672
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool shift = false;
    for (int i = 0; i < (int)a.size(); i++) {
        a[i] = tolower(a[i]);
        if (a[i] == '+') {
            shift = true;
        }
    }
    for (int i = 0; i < (int)b.size(); i++) {
        if (isupper(b[i])) {
            if (shift || a.find(tolower(b[i])) != string::npos) {
                continue;
            }
        } else {
            if (a.find(b[i]) != string::npos) {
                continue;
            }
        }
        cout << b[i];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end