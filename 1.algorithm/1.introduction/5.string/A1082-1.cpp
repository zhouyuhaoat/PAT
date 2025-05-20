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

    string value[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string weight[10] = {"", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
    string s;
    cin >> s;
    if (s[0] == '-') { // sign
        cout << "Fu ";
        s.erase(0, 1);
    }
    if (s.size() == 1) { // the first digit: no leading zero
        cout << value[s[0] - '0'];
    } else {
        cout << value[s[0] - '0'] << " " << weight[s.size()];
    }
    bool Wan = (stoi(s) / 10000 % 10000) != 0; // not all zero in 'Wan' part
    // don't read 'Wan' if all zero in 'Wan' part: 100000000 => yi Yi; 800000008: ba yi ling ba
    for (int i = 1; i < (int)s.size() - 1; i++) { // the middle digits
        if (s[i] != '0') {
            cout << " " << value[s[i] - '0'] << " " << weight[s.size() - i];
        } else {
            if (s.size() - 1 - i == 4 && Wan) { // zero in the 'Wan' digit
                cout << " Wan"; // read 'Wan' if not all zero in 'Wan' part
            } else if (s[i + 1] != '0') { // continuous zero: read the last one
                cout << " ling";
            }
        }
    }
    if (s.size() > 1 && s[s.size() - 1] != '0') { // the last digit: no weight
        cout << " " << value[s[s.size() - 1] - '0'];
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
