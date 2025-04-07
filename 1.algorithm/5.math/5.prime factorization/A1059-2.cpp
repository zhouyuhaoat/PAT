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

vector<pair<int, int>> getPrimeFactors(long n) {
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            res.emplace_back(i, cnt);
        }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
}

int main(int argc, char const *argv[]) {

    long n;
    cin >> n;
    cout << n << "=";
    if (n == 1) {
        cout << n << "\n";
        return 0;
    }
    vector<pair<int, int>> pfs = getPrimeFactors(n);
    bool first = true;
    for (auto pf : pfs) {
        if (first) {
            first = false;
        } else {
            cout << "*";
        }
        if (pf.second == 1) {
            cout << pf.first;
        } else {
            cout << pf.first << "^" << pf.second;
        }
    }
    cout << "\n";

    return 0;
}
// @pintia code=end