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

#define CLK_TCK 100 // clock tick per second

using namespace std;

int main(int argc, char const *argv[]) {

    int c1, c2;
    cin >> c1 >> c2;
    int sec = (c2 - c1) * 1.0 / CLK_TCK + 0.5;
    int hh = sec / 60 / 60, mm = sec / 60 % 60, ss = sec % 60;
    cout << setfill('0') << setw(2) << hh << ":";
    cout << setfill('0') << setw(2) << mm << ":";
    cout << setfill('0') << setw(2) << ss << "\n";

    return 0;
}
// @pintia code=end
