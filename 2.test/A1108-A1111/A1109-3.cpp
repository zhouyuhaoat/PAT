/*
 *	author:		zhouyuhao
 *	created:	2025-04-17 17:14:38
 *	modified:	2025-04-17 17:30:32
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805342720868352 pid=994805360043343872 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1109 Group Photo
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360043343872
*/

// @pintia code=start
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct peo {
    string id;
    int h;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<peo> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].h;
    }
    sort(p.begin(), p.end(), [](peo a, peo b) -> bool {
        if (a.h != b.h) {
            return a.h > b.h;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0, j = n / k + n % k; i < n; i = j, j += n / k) {
        deque<string> res; // double-ended queue: alternate, zig-zag, left & right
        for (int k = i; k < j; k++) {
            if ((k - i) % 2 == 0) {
                res.emplace_back(p[k].id);
            } else {
                res.emplace_front(p[k].id);
            }
        }
        for (int k = 0; k < (int)res.size(); k++) {
            cout << res[k];
            k < (int)res.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
