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

    string a, b;
    cin >> a >> b;
    int cnt = 0, tot = a.size();
    for (int i = 0; i < (int)b.size(); i++) {
        size_t j = a.find(b[i]);
        if (j != string::npos) {
            a.erase(j, 1);
        } else {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "Yes " << tot - b.size() << "\n";
    } else {
        cout << "No " << cnt << "\n";
    }

    return 0;
}
// @pintia code=end
