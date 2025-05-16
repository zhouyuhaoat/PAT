/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 17:43:14
 *	modified:	2023-03-23 18:56:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805297229447168 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1024 科学计数法
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805297229447168
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
