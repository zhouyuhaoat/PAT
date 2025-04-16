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

bool insertionSort(vector<int>& d1, vector<int>& d2) {
    for (int i = 2; i < (int)d1.size(); i++) {
        sort(d1.begin(), d1.begin() + i);
        if (d1 == d2) {
            sort(d1.begin(), d1.begin() + i + 1);
            return true;
        }
    }
    return false;
}

void downAdjust(vector<int>& heap, int l, int h) {
    int i = l, j = 2 * i + 1;
    while (j <= h) {
        if (j + 1 <= h && heap[j + 1] > heap[j]) { // max child
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
    int last = (int)d.size() - 1; // find the last element that is not in the right place
    while (last > 0 && d[last] > d[0]) {
        last--;
    }
    swap(d[0], d[last]);
    downAdjust(d, 0, last - 1);
}

void print(vector<int>& v) {
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
    vector<int> d3(d1);
    if (insertionSort(d3, d2)) {
        cout << "Insertion Sort\n";
        print(d3);
    } else {
        heapSort(d2);
        cout << "Heap Sort\n";
        print(d2);
    }

    return 0;
}
// @pintia code=end
