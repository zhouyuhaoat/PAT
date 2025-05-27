/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 13:53:09
 *	modified:	2023-04-04 12:57:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805344490864640 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1140 Look-and-say Sequence
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805344490864640
*/

// @pintia code=start
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string data;
    int n;
    cin >> data >> n;
    while (--n) {
        string seq;
        for (int lo = 0; lo < (int)data.size();) {
            int hi = lo + 1;
            while (hi < (int)data.size() && data[hi] == data[lo]) { // find the next different digit
                hi++;
            }
            seq += data[lo] + to_string(hi - lo); // append the digit and its count
            lo = hi;
        }
        data = seq; // update data to the new sequence
    }
    cout << data << "\n";

    return 0;
}
// @pintia code=end
