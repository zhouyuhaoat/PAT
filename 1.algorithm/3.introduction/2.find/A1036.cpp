/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 20:51:31
 *	modified:	2023-03-22 21:03:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805453203030016 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1036 Boys vs Girls
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805453203030016
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    string ml[2], fh[2];
    int mlg = 101, fhg = -1;
    bool fm = false, ff = false;
    for (int i = 0; i < n; i++) {
        string name, gender, id;
        int grade;
        cin >> name >> gender >> id >> grade;
        if (gender == "M" && grade < mlg) {
            mlg = grade;
            ml[0] = name, ml[1] = id;
            fm = true;
        } else if (gender == "F" && grade > fhg) {
            fhg = grade;
            fh[0] = name, fh[1] = id;
            ff = true;
        }
    }
    if (ff) {
        cout << fh[0] << " " << fh[1] << "\n";
    } else {
        cout << "Absent\n";
    }
    if (fm) {
        cout << ml[0] << " " << ml[1] << "\n";
    } else {
        cout << "Absent\n";
    }
    if (ff && fm) {
        cout << fhg - mlg << "\n";
    } else {
        cout << "NA\n";
    }

    return 0;
}
// @pintia code=end