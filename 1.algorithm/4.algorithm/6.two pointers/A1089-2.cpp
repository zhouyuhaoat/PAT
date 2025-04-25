/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 13:27:55
 *	modified:	2023-03-27 14:14:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805377432928256 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1089 Insert or Merge
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805377432928256
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int isInsertionSort(vector<int>& init, vector<int>& part) {
    int n = init.size(), pos = 1;
    while (pos < n && part[pos - 1] <= part[pos]) { // sorted part
        pos++;
    }
    int unsorted = pos;
    while (pos < n && init[pos] == part[pos]) { // unsorted part
        pos++;
    }
    return pos == n ? unsorted : -1;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> init(n), part(n);
    for (int i = 0; i < n; i++) {
        cin >> init[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> part[i];
    }
    int unsorted = isInsertionSort(init, part); // insertion sort: sorted part + unsorted part
    if (unsorted != -1) {
        cout << "Insertion Sort\n";
        sort(init.begin(), init.begin() + unsorted + 1);
    } else {
        int g = 2;
        while (g <= n) {
            for (int i = 0; i <= n / g; i++) {
                sort(init.begin() + i * g, init.begin() + min(n, (i + 1) * g));
            }
            g *= 2;
            if (init == part) {
                cout << "Merge Sort\n";
                for (int i = 0; i <= n / g; i++) {
                    sort(init.begin() + i * g, init.begin() + min(n, (i + 1) * g));
                }
                break;
            }
        }
    }
    for (int i = 0; i < (int)init.size(); i++) {
        cout << init[i];
        i < (int)init.size() - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
