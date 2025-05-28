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
#include <numeric>

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

int convert(int n) { // sum of each digit
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[]) {

    int N;
    cin >> N;
    for (int q = 0; q < N; q++) {
        int K, m;
        cin >> K >> m;
        cout << "Case " << q + 1 << "\n";
        /*
            m: sum of digits of A; n: sum of digits of A + 1
            gcd(m, n) is a prime number which is greater than 2
            1. n = m + 1: the gcd of two consecutive numbers always equals 1
            2. n < m: the suffix is 9s
        */
        bool flag = false;
        for (int n = 3; n < m; n++) {
            if (!(isPrime(gcd(m, n)) && gcd(m, n) > 2 && (m - n + 1) % 9 == 0)) continue;
            // m - n + 1: the sum of digits in the suffix
            int right = (m - n + 1) / 9; // the number of 9s in the suffix
            string suffix = string(right, '9');
            int left = K - right; // the number of digits in the prefix
            int sum = m - right * 9; // the sum of digits in the prefix
            if (sum >= 1 && sum <= left * 9) { // valid
                int lo = pow(10, left - 1), hi = lo * 10 - 1; // the range of the prefix
                for (int prefix = lo; prefix <= hi; prefix++) {
                    if (convert(prefix) == sum && prefix % 10 != 9) {
                        // the last digit in the prefix cannot be 9
                        cout << n << " " << prefix << suffix << "\n";
                        flag = true;
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
