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

string convert(string s, int n) {
    int dot = -1, nonZero = -1; // dot, first non-zero
    for (int i = 0; i < (int)s.size() && (dot == -1 || nonZero == -1); i++) {
        if (s[i] == '.') {
            dot = i;
        } else if (nonZero == -1 && s[i] != '0') {
            nonZero = i;
        }
    }
    if (nonZero == -1) { // all zeros
        return "0." + string(n, '0') + "*10^0";
    }
    string num; // number
    for (int i = nonZero; i < (int)s.size(); i++) {
        if ((int)num.size() < n && isdigit(s[i])) {
            num.push_back(s[i]);
        }
    }
    num.append(n - num.size(), '0'); // trailing zeros
    if (dot == -1) dot = s.size(); // dummy dot
    int e = dot - nonZero > 0 ? dot - nonZero : dot - nonZero + 1; // exponent
    // dot - nonZero > 0: nonZero ... dot => 0 dot nonZero ...
    // dot - nonZero < 0: dot 0s nonZero ... => 0 dot nonZero ...
    return "0." + num + "*10^" + to_string(e);
}

int main(int argc, char const *argv[]) {

    int n;
    string a, b;
    cin >> n >> a >> b;
    string sa = convert(a, n), sb = convert(b, n);
    if (sa == sb) {
        cout << "YES " << sa << "\n";
    } else {
        cout << "NO " << sa << " " << sb << "\n";
    }

    return 0;
}
// @pintia code=end
