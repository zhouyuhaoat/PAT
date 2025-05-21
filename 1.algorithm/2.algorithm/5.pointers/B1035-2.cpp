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

void mergeSort(vector<int>& init, vector<int>& part) {
    int n = init.size(), g = 2;
    while (g <= n) {
        for (int i = 0; i < n; i += g) {
            sort(init.begin() + i, init.begin() + min(i + g, n));
        }
        g *= 2;
        if (init == part) {
            for (int i = 0; i < n; i += g) {
                sort(init.begin() + i, init.begin() + min(i + g, n));
            }
            return;
        }
    }
}

void print(vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i];
        i < (int)vec.size() - 1 ? cout << " " : cout << "\n";
    }
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
        cout << "Merge Sort\n";
        mergeSort(init, part);
    }
    print(init);

    return 0;
}
// @pintia code=end
