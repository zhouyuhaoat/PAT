/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 09:39:36
 *	modified:	2023-04-05 09:51:29
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1478634912848322560 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1156 Sexy Primes
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478634912848322560
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
    if (isPrime(n) && (isPrime(n - 6) || isPrime(n + 6))) {
        if (isPrime(n - 6)) {
            cout << "Yes\n" << n - 6 << "\n";
        } else {
            cout << "Yes\n" << n + 6 << "\n";
        }
    } else {
        while (!(isPrime(n) && (isPrime(n - 6) || isPrime(n + 6)))) {
            n++;
        }
        cout << "No\n" << n << "\n";
    }

    return 0;
}
// @pintia code=end
