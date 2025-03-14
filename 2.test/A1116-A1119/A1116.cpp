/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 22:35:40
 *	modified:	2023-04-02 22:50:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805355358306304 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1116 Come on! Let's C
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805355358306304
*/

// @pintia code=start
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    map<string, int> r; // rank
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        r[s] = i + 1;
    }
    int k;
    cin >> k;
    map<string, int> c; // whether checked
    for (int q = 0; q < k; q++) {
        string s;
        cin >> s;
        cout << s << ": ";
        if (c[s] != 0) {
            cout << "Checked\n";
        } else {
            if (r[s] == 0) {
                cout << "Are you kidding?\n";
            } else if (++c[s] && r[s] == 1) {
                cout << "Mystery Award\n";
            } else if (isprime(r[s])) {
                cout << "Minion\n";
            } else {
                cout << "Chocolate\n";
            }
        }
    }

    return 0;
}
// @pintia code=end