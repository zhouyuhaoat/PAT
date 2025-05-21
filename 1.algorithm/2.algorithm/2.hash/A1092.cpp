/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:23:07
 *	modified:	2023-03-25 21:29:49
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805374509498368 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1092 To Buy or Not to Buy
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805374509498368
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
