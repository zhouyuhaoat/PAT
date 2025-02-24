/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:15:09
 *	modified:	2023-03-22 16:23:30
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805295203598336 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1026 程序运行时间
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805295203598336
*/

// @pintia code=start
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int c1, c2;
    cin >> c1 >> c2;
    int sec = (c2 - c1) / 100.0 + 0.5;
    int t[3] = {sec / 60 / 60, sec / 60 % 60, sec % 60};
    cout << setfill('0') << setw(2) << t[0] << ":";
    cout << setfill('0') << setw(2) << t[1] << ":";
    cout << setfill('0') << setw(2) << t[2] << "\n";

    return 0;
}
// @pintia code=end