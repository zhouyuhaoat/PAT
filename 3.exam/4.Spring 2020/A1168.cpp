/*
 *	author:		zhouyuhao
 *	created:	2023-04-06 08:29:36
 *	modified:	2023-04-06 08:49:35
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=1621700026718310400 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1168 Prime Day
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1621700026718310400
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

    string s;
    cin >> s;
    bool allPrime = true;
    for (int i = 0; i < (int)s.size(); i++) {
        string suffix = s.substr(i);
        if (isPrime(stoi(suffix))) {
            cout << suffix << " Yes\n";
        } else {
            allPrime = false;
            cout << suffix << " No\n";
        }
    }
    if (allPrime) {
        cout << "All Prime!\n";
    }

    return 0;
}
// @pintia code=end
