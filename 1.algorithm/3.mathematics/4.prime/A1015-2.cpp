/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 14:56:32
 *	modified:	2023-04-11 15:07:22
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805495863296000 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1015 Reversible Primes
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805495863296000
*/

// @pintia code=start
#include <iostream>
#include <vector>

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

vector<int> convert(int n, int base) {
    vector<int> stk; // stack -> vector for reverse order
    while (n != 0) {
        stk.emplace_back(n % base);
        n /= base;
    }
    return stk;
}

int reverse(int n, int base) {
    vector<int> stk = convert(n, base);
    /*
        秦九韶算法, Horner's Rule
            1. value = a * base^2 + b * base^1 + c * base^0
            2. value = ((0 * base + a) * base + b) * base + c
    */
    int sum = 0;
    for (int val : stk) {
        sum = sum * base + val;
    }
    return sum;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    while (n > 0) {
        int d;
        cin >> d;
        if (isPrime(n) && isPrime(reverse(n, d))) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        cin >> n;
    }

    return 0;
}
// @pintia code=end
