/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 17:32:07
 *	modified:	2023-03-22 18:50:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805442671132672 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1042 Shuffling Machine
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805442671132672
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int t;
    cin >> t;
    int n = 54; // 13 * 4 + 2 joker
    vector<int> res(n + 1), next(n + 1);
    for (int i = 1; i <= n; i++) {
        res[i] = i; // original
        cin >> next[i];
    }
    while (t--) { // shuffle multiple times
        vector<int> original = res;
        for (int i = 1; i <= n; i++) {
            res[next[i]] = original[i]; // move the j-th card to the next[j]-th position
        }
    }
    string suit = "SHCDJ";
    for (int i = 1; i <= n; i++) {
        cout << suit[(res[i] - 1) / 13] << (res[i] - 1) % 13 + 1; // 0-based suit; 1-based value
        i < n ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
