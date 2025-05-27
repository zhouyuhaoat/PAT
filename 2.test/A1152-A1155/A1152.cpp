/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 19:54:51
 *	modified:	2023-04-04 19:59:37
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=1071785055080476672 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1152 Google Recruitment
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785055080476672
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

    int l, k;
    cin >> l >> k;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size() - k + 1; i++) {
        string temp = s.substr(i, k); // each k-length substring
        if (isPrime(stoi(temp))) {
            cout << temp << "\n";
            return 0;
        }
    }
    cout << "404\n";

    return 0;
}
// @pintia code=end
