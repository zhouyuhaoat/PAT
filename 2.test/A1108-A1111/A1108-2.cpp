/*
 *	author:		zhouyuhao
 *	created:	2025-04-07 17:14:38
 *	modified:	2025-04-07 17:30:32
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805360777347072 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1108 Finding Average
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360777347072
*/

// @pintia code=start
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

bool valid(string s, double& num) {
    istringstream iss(s);
    if (!(iss >> num) || !iss.eof()) {
        // iss >> num: the string can be converted to a number
        // iss.eof(): there are any extra characters after the number
        return false;
    }
    ostringstream oss;
    oss << fixed << setprecision(2) << num;
    string formatted = oss.str(); // formatted is a string with 2 decimal places
    // and it should include the original string, to ensure that the number is accurate up to 2 decimal places
    if (formatted.substr(0, s.size()) != s || num < -1000 || num > 1000) {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        double num;
        if (valid(s, num)) {
            cnt++;
            sum += num;
        } else {
            cout << "ERROR: " << s << " is not a legal number\n";
        }
    }
    if (cnt == 0) {
        cout << "The average of 0 numbers is Undefined\n";
    } else if (cnt == 1) {
        cout << "The average of " << cnt << " number is " << fixed << setprecision(2) << sum / cnt << "\n";
    } else {
        cout << "The average of " << cnt << " numbers is " << fixed << setprecision(2) << sum / cnt << "\n";
    }

    return 0;
}
// @pintia code=end
