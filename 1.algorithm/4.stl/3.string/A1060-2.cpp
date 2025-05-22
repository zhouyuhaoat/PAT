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
#include <sstream>

using namespace std;

string convert(string s, int n) {
    int exp = stoi(s.substr(n + 3)); // exponent
    string decimal = s.substr(0, n + 1).erase(1, 1);
    if (exp != 0 || stoi(decimal) != 0) { // format for 1.234e+03 => 0.123e+04
        exp++;
    }
    return "0." + decimal + "*10^" + to_string(exp);
}

int main(int argc, char const *argv[]) {

    int n;
    long double a[2];
    cin >> n >> a[0] >> a[1];
    stringstream s[2];
    string b[2];
    for (int i = 0; i < 2; i++) {
        s[i] << scientific << setprecision(n) << a[i];
        b[i] = convert(s[i].str(), n); // i.e., 1.234e+03, not 0.123e+04
    }
    if (b[0] == b[1]) {
        cout << "YES " << b[0] << "\n";
    } else {
        cout << "NO " << b[0] << " " << b[1] << "\n";
    }

    return 0;
}
// @pintia code=end
