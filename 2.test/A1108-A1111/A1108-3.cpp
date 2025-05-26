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
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

bool valid(string s, double& num) {
    char formatted[50]; // buffer
    sscanf(s.c_str(), "%lf", &num);
    sprintf(formatted, "%.2lf", num);
    if (strncmp(s.c_str(), formatted, s.size()) != 0 || num < -1000 || num > 1000) {
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
