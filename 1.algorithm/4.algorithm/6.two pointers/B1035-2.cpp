/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 13:27:55
 *	modified:	2023-03-27 14:14:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805286714327040 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1035 插入与归并
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805286714327040
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; i++) {
        cin >> d1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d2[i];
    }
    int pos = 1; // insertion sort: sorted part + unsorted part
    while (pos < n && d2[pos - 1] <= d2[pos]) { // sorted part
        pos++;
    }
    int unsorted = pos;
    while (pos < n && d1[pos] == d2[pos]) { // unsorted part
        pos++;
    }
    if (pos == n) {
        cout << "Insertion Sort\n";
        sort(d1.begin(), d1.begin() + unsorted + 1);
    } else {
        int g = 2;
        while (true) {
            for (int i = 0; i <= n / g; i++) {
                sort(d1.begin() + i * g, d1.begin() + min(n, (i + 1) * g));
            }
            g *= 2;
            if (d1 == d2) {
                cout << "Merge Sort\n";
                for (int i = 0; i <= n / g; i++) {
                    sort(d1.begin() + i * g, d1.begin() + min(n, (i + 1) * g));
                }
                break;
            }
        }
    }
    for (int i = 0; i < (int)d1.size(); i++) {
        cout << d1[i];
        i < (int)d1.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
