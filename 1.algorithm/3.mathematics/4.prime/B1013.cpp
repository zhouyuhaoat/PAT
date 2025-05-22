/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 22:38:14
 *	modified:	2023-04-10 22:38:18
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805260223102976 pid=994805309963354112 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1013 数素数
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805309963354112
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6;
vector<int> prime;
vector<bool> isPrime(N, true);

void sieve() { // Sieve of Eratosthenes
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            prime.emplace_back(i);
            for (int j = 2 * i; j < N; j += i) { // multiples
                isPrime[j] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    sieve();
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        cout << prime[i - 1];
        if ((i - m + 1) % 10 == 0) {
            cout << "\n";
        } else {
            i < n ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
