/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 09:17:00
 *	modified:	2024-05-04 09:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805413520719872 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1060 Are They Equal
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805413520719872
*/

// @pintia code=start
#include <iostream>

using namespace std;

string trans(string s, int n) {
    while (s[0] == '0' && s.size() > 1 && s[1] != '.') { // leading zeros
        s.erase(0, 1);
    }
    int dot = -1, nonZero = -1; // dot, first non-zero
    for (int i = 0; i < (int)s.size() && (dot == -1 || nonZero == -1); i++) {
        if (s[i] == '.') {
            dot = i;
        } else if (nonZero == -1 && s[i] != '0') {
            nonZero = i;
        }
    }
    int e = 0;
    string num;
    if (nonZero != -1) { // not zero
        // exponent
        if (nonZero == 0) { // nonZero + ...
            if (dot != -1) {
                s.erase(dot, 1); // remove dot for number
                e = dot;
            } else {
                e = s.size();
            }
        } else { // 0. + zero + nonZero + ...
            e = -(nonZero - dot - 1);
        }
        // number
        num = s.substr(nonZero, n);
    } // else: zero
    if ((int)num.size() < n) { // trailing zeros
        num.append(n - num.size(), '0');
    }
    return "0." + num + "*10^" + to_string(e);
}

int main(int argc, char const *argv[]) {

    int n;
    string a, b;
    cin >> n >> a >> b;
    string sa = trans(a, n), sb = trans(b, n);
    if (sa == sb) {
        cout << "YES " << sa << "\n";
    } else {
        cout << "NO " << sa << " " << sb << "\n";
    }

    return 0;
}
// @pintia code=end