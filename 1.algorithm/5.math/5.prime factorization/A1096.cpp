/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:19:04
 *	modified:	2023-04-11 20:00:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=994805370650738688 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1096 Consecutive Factors
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805370650738688
*/

// @pintia code=start
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int f = 1, l = 0; // f: first factor, l: length
    for (int i = 2; i <= (int)sqrt(n); i++) {
        int p = 1; // product of consecutive factors
        for (int j = i; j <= (int)sqrt(n); j++) {
            p *= j;
            if (n % p != 0) {
                break;
            }
            if (j - i + 1 > l) {
                l = j - i + 1;
                f = i;
            }
        }
    }
    if (l == 0) {
        cout << f << "\n" << n << "\n";
    } else {
        cout << l << "\n";
        for (int i = 0; i < l; i++) {
            cout << f + i;
            if (i < l - 1) {
                cout << "*";
            } else {
                cout << "\n";
            }
        }
    }

    return 0;
}
// @pintia code=end