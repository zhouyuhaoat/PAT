/*
 *	author:		zhouyuhao
 *	created:	2025-04-06 19:28:28
 *	modified:	2025-04-06 21:55:49
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=1478635415925800960 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1160 Forever
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1478635415925800960
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int K, m, n, suffix;
vector<int> prefix;
// K: number of digits; m: sum of digits fo A; n: sum of digits of A + 1
// suffix: number of trailing 9s; prefix: number in reverse order

vector<int> getPrimeFactors(int n) { // prime factorization
    vector<int> pfs;
    for (int i = 2; i * i <= n; i++) { // the smallest prime
        if (n % i == 0) { // factor
            while (n % i == 0) { // trial division
                n /= i;
            }
            pfs.emplace_back(i);
        }
    }
    if (n > 1) {
        pfs.emplace_back(n);
    }
    return pfs;
}

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

void dfs(int k, int sum, vector<pair<int, int>>& res) {
    if ((K - k) * 9 + sum < m) return; // remaining digits can't reach the target sum
    if (k > K || sum > m) return; // exceeded bounds
    if (k == K && sum == m) {
        if (prefix.back() != 0 && prefix[0] != 9) {
            // the first digit cannot be 0 and the last digit cannot be 9
            int A = 0; // the number to be formed
            for (int i = prefix.size() - 1; i >= 0; i--) {
                A = A * 10 + prefix[i];
            }
            for (int i = 1; i <= suffix; i++) {
                A = A * 10 + 9;
            }
            res.emplace_back(n, A);
            return;
        }
    }
    for (int i = 0; i <= 9; i++) { // try each possible digit
        prefix.emplace_back(i);
        dfs(k + 1, sum + i, res);
        prefix.pop_back();
    }
}

int main(int argc, char const *argv[]) {

    int N;
    cin >> N;
    for (int q = 0; q < N; q++) {
        cin >> K >> m;
        cout << "Case " << q + 1 << "\n";
        vector<int> pfs = getPrimeFactors(m);
        if (!pfs.empty() && pfs.back() <= 2) {
            cout << "No Solution\n";
            continue;
        }
        vector<pair<int, int>> res;
        for (int pf : pfs) {
            if (pf <= 2) continue;
            for (int i = 1; pf * i < m; i++) { // multiple of prime factor
                n = pf * i;
                // if (!isPrime(gcd(m, n))) continue; // gcd(52, 26) = 26, not prime
                if ((m - n + 1) % 9 == 0) { // tailing 9s
                    suffix = (m - n + 1) / 9; // suffix > 0
                    if (K > suffix) { // prefix not empty
                        dfs(suffix, suffix * 9, res); // search prefix
                    }
                }
            }
        }
        if (!res.empty()) {
            sort(res.begin(), res.end());
            for (auto [n, A] : res) {
                cout << n << " " << A << "\n";
            }
        } else {
            cout << "No Solution\n";
        }
    }

    return 0;
}
// @pintia code=end
