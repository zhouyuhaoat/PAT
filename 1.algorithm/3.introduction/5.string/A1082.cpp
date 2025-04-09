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

    string p[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string w[10] = {"", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
    string s;
    cin >> s;
    if (s[0] == '-') { // sign
        cout << "Fu ";
        s.erase(0, 1);
    }
    // the first digit: no leading zero
    if (s.size() == 1) {
        cout << p[s[0] - '0'];
    } else {
        cout << p[s[0] - '0'] << " " << w[s.size()];
    }
    // the middle digits except the first and the last digit
    bool flag = (stoi(s) / 10000 % 10000) != 0; // whether all zero in 'Wan' part
    // not read 'Wan' if all zero in 'Wan' part: 100000000 => yi Yi; 800000008: ba yi ling ba
    for (int i = 1; i < (int)s.size() - 1; i++) {
        if (s[i] != '0') { // value + weight
            cout << " " << p[s[i] - '0'] << " " << w[s.size() - i];
        } else {
            if (s.size() - i == 5 && flag) { // zero in divine line: don't read
                cout << " Wan"; // read 'Wan' if not all zero in 'Wan' part
            } else if (s[i + 1] != '0') { // continuous zero: read the last one
                cout << " ling";
            }
        }
    }
    // the last digit: no weight
    if (s.size() > 1 && s[s.size() - 1] != '0') {
        cout << " " << p[s[s.size() - 1] - '0'];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
