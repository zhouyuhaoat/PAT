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
#include <cmath>
#include <iostream>

using namespace std;

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    string s;
    cin >> s;
    bool allprime = true;
    for (int i = 0; i < (int)s.size(); i++) {
        string ss = s.substr(i); // suffix
        if (isprime(stoi(ss))) {
            cout << ss << " Yes\n";
        } else {
            allprime = false;
            cout << ss << " No\n";
        }
    }
    if (allprime) {
        cout << "All Prime!\n";
    }

    return 0;
}
// @pintia code=end