/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-20 10:48:08
 * 	 modified: 	2025-02-20 12:59:45
 * 	 project: 	Programming Ability Test
 * 	 venue: 	914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805413520719872 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1060 Are They Equal
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805413520719872
*/

// @pintia code=start
// Not Accepted only by test 5, due to the precision of the 99-digits long float number
#include <iostream>
#include <sstream>

using namespace std;

string normalize(long double num, int n) {

    if (num == 0) return "0." + string(n, '0') + "*10^0";
    int exp = 1;
    while (num >= 10) {
        num /= 10;
        exp++;
    }
    while (num < 1) {
        num *= 10;
        exp--;
    }
    string s = to_string(num);
    s.erase(s.find('.'), 1);
    if (s.size() < (size_t)n) {
        s.append(n - s.size(), '0');
    } else {
        s = s.substr(0, n);
    }
    return "0." + s + "*10^" + to_string(exp);
}

int main(int argc, char const *argv[]) {

    int n;
    long double a, b;
    cin >> n >> a >> b;
    string sa = normalize(a, n), sb = normalize(b, n);
    if (sa == sb) {
        cout << "YES " << sa << "\n";
    } else {
        cout << "NO " << sa << " " << sb << "\n";
    }

    return 0;
}
// @pintia code=end