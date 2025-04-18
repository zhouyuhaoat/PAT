/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 20:10:27
 *	modified:	2023-04-02 22:27:58
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805360043343872 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1109 Group Photo
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805360043343872
*/

// @pintia code=start
#include <algorithm>
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
        // i: the start index of the current row; j: the start index of the next row
        vector<string> res(j - i);
        int mi = res.size() / 2, dir = -1; // direction
        res[mi] = p[i].id;
        for (int k = i + 1; k < j; k++) {
            int offset = (k - i - 1) / 2 + 1;
            res[mi + offset * dir] = p[k].id;
            dir = -dir;
        }
        for (int k = 0; k < (int)res.size(); k++) {
            cout << res[k];
            k < (int)res.size() - 1 ? cout << " " : cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end
