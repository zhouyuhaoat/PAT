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

    string broken, original;
    getline(cin, broken), getline(cin, original);
    bool shift = broken.find('+') != string::npos;
    string typed;
    for (char ch : original) {
        if (isupper(ch)) {
            if (shift || broken.find(ch) != string::npos) {
                continue;
            }
        } else {
            if (broken.find(toupper(ch)) != string::npos) {
                continue;
            }
        }
        typed += ch;
    }
    cout << typed << "\n";

    return 0;
}
// @pintia code=end
