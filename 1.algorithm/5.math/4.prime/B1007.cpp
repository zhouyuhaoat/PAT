/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 22:17:26
 *	modified:	2023-04-10 22:23:36
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805260223102976 pid=994805317546655744 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1007 素数对猜想
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805317546655744
*/

// @pintia code=start
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i) && isPrime(i - 2)) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
// @pintia code=end
