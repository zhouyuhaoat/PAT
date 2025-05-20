/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 17:08:58
 *	modified:	2023-03-23 17:37:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805411985604608 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1061 Dating
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805411985604608
*/

// @pintia code=start
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = min(a.size(), b.size()), idx = 0; // the first two strings
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) { // the first common character
            if (a[i] >= 'A' && a[i] <= 'G') { // the first 7 letters
                cout << week[a[i] - 'A'] << " ";
                idx = i;
                break;
            }
        }
    }
    for (int i = idx + 1; i < n; i++) {
        if (a[i] == b[i]) { // the second common character
            if (isdigit(a[i])) {
                cout << setfill('0') << setw(2) << a[i] << ":";
                break;
            } else if (a[i] >= 'A' && a[i] <= 'N') { // the first 14 letters
                cout << a[i] - 'A' + 10 << ":";
                break;
            }
        }
    }
    int m = min(c.size(), d.size()); // the last two strings
    for (int i = 0; i < m; i++) {
        if (c[i] == d[i] && isalpha(c[i])) { // the English letter shared
            cout << setfill('0') << setw(2) << i << "\n";
            break;
        }
    }

    return 0;
}
// @pintia code=end
