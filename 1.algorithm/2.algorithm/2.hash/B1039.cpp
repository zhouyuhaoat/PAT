/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:23:07
 *	modified:	2023-03-25 21:29:49
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805283241443328 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1039 到底买不买
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805283241443328
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string have, need;
    cin >> have >> need;
    int missing = 0, extra = have.size();
    for (char ch : need) {
        if (have.find(ch) != string::npos) { // meet
            extra--;
            have.erase(have.find(ch), 1);
        } else {
            missing++;
        }
    }
    if (missing == 0) {
        cout << "Yes " << extra << "\n";
    } else {
        cout << "No " << missing << "\n";
    }

    return 0;
}
// @pintia code=end
