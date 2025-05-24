/*
 *	author:		zhouyuhao
 *	created:	2023-03-29 23:46:48
 *	modified:	2023-03-30 00:26:53
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805368847187968 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1098 Insertion or Heap Sort
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805368847187968
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isHeapSort(vector<int>& init, vector<int>& part) {
    for (int i = 0; i < (int)init.size(); i++) {
        pop_heap(init.begin(), init.end() - i);
        if (init == part) {
            pop_heap(init.begin(), init.end() - i - 1);
            return true;
        }
    }
    return false;
}

void insertionSort(vector<int>& part) {
    auto pos = is_sorted_until(part.begin(), part.end());
    auto insert = upper_bound(part.begin(), pos, *pos);
    rotate(insert, pos, pos + 1);
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
    make_heap(init.begin(), init.end());
    if (isHeapSort(init, part)) {
        cout << "Heap Sort\n";
        print(init);
    } else {
        cout << "Insertion Sort\n";
        insertionSort(part);
        print(part);
    }

    return 0;
}
// @pintia code=end
