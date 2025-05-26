/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 19:46:31
 *	modified:	2023-04-01 20:09:12
 *	item:		Programming Ability Test
 *	site:		Yuting
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

using namespace std;

bool valid(string s, double& num) {
    try {
        size_t pos; // the number of characters processed
        num = stod(s, &pos);
        if (pos < s.size()) { // there are any extra characters after the number
            return false;
        }
    } catch (...) {
        // stod throws an exception if the conversion fails
        // 1. std::invalid_argument; 2. std::out_of_range
        return false;
    }
    if (num < -1000 || num > 1000) {
        return false;
    }
    size_t dot = s.find('.');
    if (dot != string::npos && s.size() - dot > 3) { // accurate up to no more than 2 decimal place
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
