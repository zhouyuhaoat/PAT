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
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string bet = "WTL";
    double res = 1;
    for (int i = 0; i < 3; i++) {
        double maxOdd = 0;
        int id = 0;
        for (int j = 0; j < 3; j++) {
            double odd;
            cin >> odd;
            if (odd > maxOdd) {
                maxOdd = odd;
                id = j;
            }
        }
        res *= maxOdd;
        cout << bet[id] << " ";
    }
    res = (res * 0.65 - 1) * 2;
    cout << fixed << setprecision(2) << res << "\n";

    return 0;
}
// @pintia code=end
