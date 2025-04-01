/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:28:28
 *	modified:	2023-04-05 21:55:49
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
  @pintia psid=994805342720868352 pid=1478635415925800960 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1160 Forever
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635415925800960
*/

// @pintia code=start
#include <cmath>
#include <iostream>

using namespace std;

bool isprime(int n) {
    if (n <= 2) {
        return false;
    }
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) { // greatest common divisor
    return !b ? a : gcd(b, a % b);
}

int getsum(int n) { // sum of digits
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    for (int q = 0; q < n; q++) {
        int k, m;
        cin >> k >> m;
        cout << "Case " << q + 1 << "\n";
        // the greatest common divisor of m and n is a prime number which is greater than 2.
        // 1. n = m + 1: the gcd of two consecutive numbers always equals 1
        // 2. n < m: the suffix is 9s
        bool flag = false;
        for (int i = 3; i < m; i++) {
            if (isprime(gcd(m, i))) {
                if ((m - i + 1) % 9 == 0) { // m - i + 1: the number of digits in the suffix
                    int rc = (m - i + 1) / 9; // the number of 9s in the suffix
                    string suffix = string(rc, '9');
                    int lc = k - rc; // the number of digits in the prefix
                    int sum = m - rc * 9; // the sum of digits in the prefix
                    if (sum >= 1 && sum <= lc * 9) { // valid
                        int lj = pow(10, lc - 1), rj = lj * 10 - 1; // the range of the prefix
                        for (int j = lj; j <= rj; j++) {
                            if (getsum(j) == sum && j % 10 != 9) { // the last digit in the prefix is not 9
                                cout << i << " " << j << suffix << "\n";
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        if (!flag) {
            cout << "No Solution\n";
        }
    }

    return 0;
}
// @pintia code=end