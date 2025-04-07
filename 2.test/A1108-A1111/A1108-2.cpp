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

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        istringstream iss(s); // parse the string
        double temp;
        if (!(iss >> temp) || !iss.eof()) {
            // iss.eof() checks if there are any extra characters after the number
            cout << "ERROR: " << s << " is not a legal number\n";
            continue;
        }
        ostringstream oss; // format the number
        oss << fixed << setprecision(2) << temp;
        string formatted = oss.str(); // convert to string
        bool flag = false;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] != formatted[j]) {
                flag = true;
                break;
            }
        }
        if (flag || temp < -1000 || temp > 1000) {
            cout << "ERROR: " << s << " is not a legal number\n";
        } else {
            cnt++;
            sum += temp;
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