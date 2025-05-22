/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:26:39
 *	modified:	2023-04-11 20:34:38
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805415005503488 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1059 Prime Factors
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805415005503488
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) { // Sieve of Eratosthenes
    vector<int> prime;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime.emplace_back(i);
            for (int j = 2 * i; j <= n; j += i) { // multiples
                isPrime[j] = false;
            }
        }
    }
    return prime;
}

int main(int argc, char const *argv[]) {

    vector<int> prime = sieve(1e5);
    long long n;
    cin >> n;
    cout << n << "=";
    if (n == 1) {
        cout << n << "\n";
        return 0;
    }
    long long temp = n;
    for (int i = 0; i < (int)prime.size() && prime[i] * prime[i] <= temp; i++) {
        if (n % prime[i] == 0) {
            int cnt = 0;
            while (n % prime[i] == 0) {
                cnt++;
                n /= prime[i];
            }
            if (cnt == 1) {
                cout << prime[i];
            } else {
                cout << prime[i] << "^" << cnt;
            }
            if (n != 1) { // not the last prime factor
                cout << "*";
            } else {
                break;
            }
        }
    }
    if (n != 1) {
        cout << n;
    }
    cout << "\n";

    return 0;
}
// @pintia code=end
