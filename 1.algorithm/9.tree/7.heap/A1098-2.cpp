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

int isInsertionSort(vector<int>& d1, vector<int>& d2) {
    int pos = 1;
    while (pos < (int)d1.size() && d2[pos - 1] <= d2[pos]) { // sorted part
        pos++;
    }
    int unsorted = pos;
    while (pos < (int)d1.size() && d1[pos] == d2[pos]) { // unsorted part
        pos++;
    }
    return pos == (int)d1.size() ? unsorted : -1;
}

void downAdjust(vector<int>& heap, int l, int h) {
    int i = l, j = 2 * i + 1;
    while (j <= h) {
        if (j + 1 <= h && heap[j + 1] > heap[j]) {
            j++;
        }
        if (heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
}

void heapSort(vector<int>& d) {
    auto it = std::find_if(d.rbegin(), d.rend(), [&](int v) {
        return v <= d[0];
    });
    int last = (int)d.size() - 1 - (it - d.rbegin());
    swap(d[0], d[last]);
    downAdjust(d, 0, last - 1);
}

void print(vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        i < (int)v.size() - 1 ? cout << " " : cout << "\n";
    }
}

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
    int unsorted = isInsertionSort(d1, d2); // insertion sort: sorted part + unsorted part
    if (unsorted != -1) {
        cout << "Insertion Sort\n";
        sort(d1.begin(), d1.begin() + unsorted + 1);
        print(d1);
    } else {
        cout << "Heap Sort\n";
        heapSort(d2);
        print(d2);
    }

    return 0;
}
// @pintia code=end
