/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 20:57:47
 *	modified:	2023-03-26 21:06:55
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805432256675840 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1048 Find Coins
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805432256675840
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (d[i] + d[j] < m) {
            i++;
        } else if (d[i] + d[j] > m) {
            j--;
        } else if (d[i] + d[j] == m) {
            cout << d[i] << " " << d[j] << "\n";
            return 0;
        }
    }
    cout << "No Solution\n";

    return 0;
}
// @pintia code=end
