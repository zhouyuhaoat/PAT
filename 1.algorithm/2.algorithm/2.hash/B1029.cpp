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

using namespace std;

int main(int argc, char const *argv[]) {

    string original, typed;
    cin >> original >> typed;
    string broken;
    for (char ch : original) {
        if (typed.find(ch) == string::npos) { // broken
            ch = toupper(ch);
            if (broken.find(ch) == string::npos) { // print only once
                broken += ch;
            }
        }
    }
    cout << broken << "\n";

    return 0;
}
// @pintia code=end
