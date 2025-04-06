/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 17:43:14
 *	modified:	2023-03-23 18:56:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805395707510784 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1073 Scientific Notation
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805395707510784
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string a;
    cin >> a;
    if (a[0] == '-') { // numSign
        cout << a[0];
    }
    a.erase(0, 1);
    size_t E = a.find('E'); // posE
    int e = stoi(a.substr(E + 1)); // exp
    a.erase(E); // intPart + point + frac
    a.erase(1, 1); // point
    if (e < 0) {
        a.insert(0, abs(e), '0');
        a.insert(1, ".");
    } else if (e > 0) {
        int right = a.size() - 1; // frac
        if (e >= right) {
            a.insert(a.size(), e - right, '0');
        } else {
            a.insert(e + 1, ".");
        }
    } else { // e == 0
        a.insert(1, ".");
    }
    cout << a << "\n";

    return 0;
}
// @pintia code=end