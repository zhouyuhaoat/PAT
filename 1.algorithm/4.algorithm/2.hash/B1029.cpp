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
    string res; // broken
    for (int i = 0; i < (int)original.size(); i++) {
        if (typed.find(original[i]) == string::npos) { // broken
            original[i] = toupper(original[i]);
            if (res.find(original[i]) == string::npos) { // print only once
                res += original[i];
            }
        }
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
