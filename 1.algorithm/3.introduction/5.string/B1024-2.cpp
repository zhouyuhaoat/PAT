/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-18 12:59:53
 * 	 modified: 	2025-02-18 13:04:04
 * 	 project: 	Programming Ability Test
 * 	 venue: 	914, Harbin
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
    char numSign = s[0], intPart = s[1];
    int posE = s.find('E');
    string frac = s.substr(3, posE - 3);
    char expSign = s[posE + 1];
    int expVal = stoi(s.substr(posE + 2));

    string res;
    if (numSign == '-') {
        res += "-";
    }
    if (expSign == '+') {
        if (expVal < (int)frac.size()) {
            res.push_back(intPart);
            res.append(frac, 0, expVal);
            res.push_back('.');
            res.append(frac, expVal);
        } else {
            res.push_back(intPart);
            res.append(frac);
            res.append(expVal - frac.size(), '0');
        }
    } else {
        if (expVal > 0) {
            res += "0.";
            res.append(expVal - 1, '0');
            // append's first arg: can not be negative
            res.push_back(intPart);
            res.append(frac);
        } else { // expVal == 0
            res += s.substr(1, 3);
        }
    }
    cout << res;

    return 0;
}
// @pintia code=end