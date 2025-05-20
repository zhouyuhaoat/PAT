/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:15:00
 *	modified:	2023-03-22 22:18:43
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805318855278592 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1006 换个格式输出整数
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805318855278592
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    cout << string(n / 100, 'B') << string(n / 10 % 10, 'S');
    for (int i = 1; i <= n % 10; i++) {
        cout << i;
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
