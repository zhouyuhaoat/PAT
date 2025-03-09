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
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5;

vector<int> p;
vector<bool> isprime(maxn, true);

void sieve() { // sieve of Eratosthenes
    for (int i = 2; i <= maxn; i++) {
        if (isprime[i]) {
            p.emplace_back(i);
            for (int j = 2 * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    sieve();
    long n;
    cin >> n;
    cout << n << "=";
    if (n == 1) {
        cout << n << "\n";
        return 0;
    }
    long t = n; // copy of n
    for (int i = 0; i < (int)p.size() && p[i] <= (int)sqrt(n); i++) {
        if (t % p[i] == 0) {
            int cnt = 0;
            while (t % p[i] == 0) {
                ++cnt;
                t /= p[i];
            }
            if (cnt == 1) {
                cout << p[i];
            } else {
                cout << p[i] << "^" << cnt;
            }
            if (t != 1) {
                cout << "*";
            } else {
                break;
            }
        }
    }
    if (t != 1) {
        cout << t;
    }
    cout << "\n";

    return 0;
}
// @pintia code=end