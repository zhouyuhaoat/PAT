/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:02:14
 *	modified:	2023-03-22 16:04:53
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805312417021952 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1011 A+B 和 C
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805312417021952
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i + 1;
        a + b > c ? cout << ": true\n" : cout << ": false\n";
    }

    return 0;
}
// @pintia code=end
