/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 13:30:00
 *	modified:	2024-04-27 13:35:00
 *	item:		Programming Ability Test
 *	site:		Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805306310115328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1016 部分A+B
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805306310115328
*/

// @pintia code=start
#include <iostream>

using namespace std;

int convert(string s, char ch) {
    int res = 0;
    for (char c : s) {
        if (c == ch) {
            res = res * 10 + (ch - '0');
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {

    string a, b;
    char d1, d2; // digit
    cin >> a >> d1 >> b >> d2;
    int p1 = convert(a, d1), p2 = convert(b, d2); // partial
    cout << p1 + p2 << "\n";

    return 0;
}
// @pintia code=end
