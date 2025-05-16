/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-18 12:59:53
 * 	 modified: 	2025-02-18 13:04:04
 * 	 project: 	Programming Ability Test
 * 	 venue: 	914, Harbin
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
    // sign integer . decimal E expSign expVal
    char sign = s[0], integer = s[1];
    int posE = s.find('E');
    string decimal = s.substr(3, posE - 3);
    char expSign = s[posE + 1];
    int expVal = stoi(s.substr(posE + 2));

    string res;
    if (sign == '-') {
        res += sign;
    }

    if (expSign == '+') {
        res.push_back(integer);
        if (expVal >= (int)decimal.size()) {
            res.append(decimal);
            res.append(expVal - decimal.size(), '0');
        } else {
            res.append(decimal, 0, expVal);
            res.push_back('.');
            res.append(decimal, expVal);
        }
    } else {
        if (expVal > 0) {
            res += "0.";
            res.append(expVal - 1, '0'); // append's first arg: can not be negative
            res.push_back(integer);
            res.append(decimal);
        } else { // expVal == 0
            res.push_back(integer);
            res.push_back('.');
            res.append(decimal);
        }
    }

    cout << res << "\n";

    return 0;
}
// @pintia code=end
