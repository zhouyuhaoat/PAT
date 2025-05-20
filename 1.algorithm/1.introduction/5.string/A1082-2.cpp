/*
 *	author:		zhouyuhao
 *	created:	2024-05-01 21:42:15
 *	modified:	2024-05-01 21:50:15
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805385053978624 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1082 Read Number in Chinese
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805385053978624
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string value[10] = {" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"}; // space
    string weight[10] = {"", "", " Shi", " Bai", " Qian", " Wan", " Shi", " Bai", " Qian", " Yi"};
    string s;
    cin >> s;
    string res;
    if (s[0] == '-') {
        res += "Fu";
        s.erase(0, 1);
    }
    bool leadingZero = false, part = false; // each part or group of 4 digits
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != '0') {
            if (leadingZero) {
                res += " ling";
            }
            res += value[s[i] - '0'] + weight[s.size() - i];
            leadingZero = false, part = true;
        } else {
            if (i == 0) { // 0: leading zero at the beginning
                res += " ling";
            }
            leadingZero = true;
        }
        if ((s.size() - 1 - i) % 4 == 0) { // new part or group
            // size - 1 - i: the number of digits right, exclude the current digit
            if (s[i] == '0' && part) {
                res += weight[s.size() - i];
            }
            leadingZero = false, part = false;
        }
    }
    if (res[0] == ' ') { // positive or zero
        res.erase(0, 1);
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
