/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 20:26:50
 *	modified:	2023-03-22 20:40:06
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805504927186944 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1011 World Cup Betting
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805504927186944
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    char ch[3] = {'W', 'T', 'L'};
    double result = 1;
    for (int i = 0; i < 3; i++) {
        double o[3];
        for (int j = 0; j < 3; j++) {
            cin >> o[j];
        }
        double *max_ptr = max_element(o, o + 3);
        result *= *max_ptr;
        cout << ch[max_ptr - o] << " ";
    }
    result = (result * 0.65 - 1) * 2;
    cout << fixed << setprecision(2) << result << "\n";

    return 0;
}
// @pintia code=end