/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 17:43:14
 *	modified:	2023-03-23 18:56:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805395707510784 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1073 Scientific Notation
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805395707510784
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;

    // format: [+-][1-9].[0-9]+E[+-][0-9]+
    // sign integer . decimal E exp
    char sign = s[0], integer = s[1];
    int posE = s.find('E');
    string decimal = s.substr(3, posE - 3);
    int exp = stoi(s.substr(posE + 1));

    string res;
    if (sign == '-') {
        res += sign;
    }

    if (exp > 0) {
        res.push_back(integer);
        if (exp >= (int)decimal.size()) {
            res.append(decimal);
            res.append(exp - decimal.size(), '0');
        } else {
            res.append(decimal, 0, exp);
            res.push_back('.');
            res.append(decimal, exp);
        }
    } else if (exp < 0) {
        res += "0.";
        res.append(abs(exp) - 1, '0');
        res.push_back(integer);
        res.append(decimal);
    } else {
        res.push_back(integer);
        res.push_back('.');
        res.append(decimal);
    }

    cout << res << "\n";

    return 0;
}
// @pintia code=end
