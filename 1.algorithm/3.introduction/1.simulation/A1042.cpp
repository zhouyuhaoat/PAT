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

    int k;
    cin >> k;
    const int n = 54;
    vector<int> res(n + 1), next(n + 1);
    for (int i = 1; i <= n; i++) {
        res[i] = i;
        cin >> next[i];
    }
    for (int i = 0; i < k; i++) {
        vector<int> temp = res;
        for (int j = 1; j <= n; j++) {
            res[next[j]] = temp[j]; // move the j-th card to the next[j]-th position
        }
    }
    string suit = "SHCDJ"; // 0-based suit = (id - 1) / 13; 1-based value = (id - 1) % 13 + 1
    for (int i = 1; i <= n; i++) {
        cout << suit[(res[i] - 1) / 13] << (res[i] - 1) % 13 + 1;
        i < n ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
