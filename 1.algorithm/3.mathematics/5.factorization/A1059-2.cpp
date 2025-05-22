/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 15:26:39
 *	modified:	2025-04-07 17:06:38
 *	item:		Programming Ability Test
 *	site:		914, Harbin
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

vector<pair<int, int>> getPrimeFactors(long long n) {
    vector<pair<int, int>> pfs;
    for (int i = 2; i * i <= n; i++) { // the smallest prime
        if (n % i == 0) { // factor
            int cnt = 0; // exponent
            while (n % i == 0) { // trial division
                cnt++;
                n /= i;
            }
            pfs.emplace_back(i, cnt);
        }
    }
    if (n > 1) {
        pfs.emplace_back(n, 1);
    }
    return pfs;
}

int main(int argc, char const *argv[]) {

    long long n;
    cin >> n;
    cout << n << "=";
    if (n == 1) {
        cout << n << "\n";
        return 0;
    }
    vector<pair<int, int>> pfs = getPrimeFactors(n);
    for (int i = 0; i < (int)pfs.size(); i++) {
        if (pfs[i].second == 1) {
            cout << pfs[i].first;
        } else {
            cout << pfs[i].first << "^" << pfs[i].second;
        }
        i < (int)pfs.size() - 1 ? cout << "*" : cout << "\n";
    }

    return 0;
}
// @pintia code=end
