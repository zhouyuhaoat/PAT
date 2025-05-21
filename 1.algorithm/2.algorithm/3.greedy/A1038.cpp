/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 10:47:08
 *	modified:	2023-03-26 11:10:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805449625288704 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1038 Recover the Smallest Number
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805449625288704
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<string> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> seg[i];
    }
    /*
        forming the smallest number from strings of digits
        - sort the strings by each pair of strings' concatenation: a + b < b + a
    */
    sort(seg.begin(), seg.end(), [](string a, string b) {
        return a + b < b + a;
    });
    string res;
    for (string s : seg) {
        res += s;
    }
    res.erase(0, res.find_first_not_of('0')); // leading zeros
    res.empty() ? cout << "0\n" : cout << res << "\n"; // avoid all are zeros

    return 0;
}
// @pintia code=end
