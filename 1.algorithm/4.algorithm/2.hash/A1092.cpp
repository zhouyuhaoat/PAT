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
    int cnt = 0, total = have.size();
    for (int i = 0; i < (int)need.size(); i++) {
        size_t j = have.find(need[i]);
        if (j != string::npos) { // meet
            have.erase(j, 1);
        } else { // missing
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "Yes " << total - need.size() << "\n";
    } else {
        cout << "No " << cnt << "\n";
    }

    return 0;
}
// @pintia code=end
