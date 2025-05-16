/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:39:47
 *	modified:	2023-03-22 22:45:38
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805324509200384 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1002 写出这个数
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805324509200384
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    int sum = 0;
    for (char ch : s) {
        sum += ch - '0';
    }
    s = to_string(sum);
    string phonetic[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (int i = 0; i < (int)s.size(); i++) {
        cout << phonetic[s[i] - '0'];
        i < (int)s.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
