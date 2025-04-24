/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 22:02:14
 *	modified:	2023-03-25 22:21:19
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805320306507776 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1005 继续(3n+1)猜想
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805320306507776
*/

// @pintia code=start
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int k;
    cin >> k;
    vector<int> data(k);
    for (int i = 0; i < k; i++) {
        cin >> data[i];
    }
    set<int, greater<int>> res;
    unordered_map<int, bool> cover;
    for (int i = 0; i < k; i++) {
        int n = data[i];
        while (n != 1) {
            if (n % 2 != 0) {
                n = 3 * n + 1;
            }
            n /= 2;
            if (cover[n]) {
                break;
            }
            cover[n] = true;
        }
    }
    for (int n : data) {
        if (!cover[n]) {
            res.emplace(n);
        }
    }
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it;
        next(it) != res.end() ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
