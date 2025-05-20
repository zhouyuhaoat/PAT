/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:06:59
 *	modified:	2023-03-22 16:13:04
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805306310115328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1016 部分A+B
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805306310115328
*/

// @pintia code=start
#include <algorithm>
#include <iostream>

using namespace std;

int convert(string s, char ch) {
    int cnt = count(s.begin(), s.end(), ch);
    return cnt != 0 ? stoi(string(cnt, ch)) : 0;
}

int main(int argc, char const *argv[]) {

    string a, b;
    char d1, d2;
    cin >> a >> d1 >> b >> d2;
    int p1 = convert(a, d1), p2 = convert(b, d2);
    cout << p1 + p2 << "\n";

    return 0;
}
// @pintia code=end
