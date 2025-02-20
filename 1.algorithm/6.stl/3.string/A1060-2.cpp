/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 10:17:00
 *	modified:	2024-05-04 10:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
  @pintia psid=994805342720868352 pid=994805413520719872 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1060 Are They Equal
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805413520719872
*/

// @pintia code=start
// Not Accepted only by test 5, due to the precision of the 99-digits long float number
#include <iomanip>
#include <iostream>

using namespace std;

string trans(string s, int n) {
    int e = stoi(s.substr(n + 3));
    string t = s.substr(0, n + 1);
    t.erase(1, 1);
    if (e != 0 || stoi(t) != 0) {
        ++e;
    }
    return "0." + t + "*10^" + to_string(e);
}

int main(int argc, char const *argv[]) {

    int n;
    float a[2];
    cin >> n >> a[0] >> a[1];
    stringstream s[2];
    string b[2];
    for (int i = 0; i < 2; i++) {
        s[i] << scientific << setprecision(n) << a[i];
        // i.e., 1.234e+03, not 0.123e+03
        b[i] = trans(s[i].str(), n);
    }
    if (b[0] == b[1]) {
        cout << "YES " << b[0] << "\n";
    } else {
        cout << "NO " << b[0] << " " << b[1] << "\n";
    }

    return 0;
}
// @pintia code=end