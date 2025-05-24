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

int isInsertionSort(vector<int>& init, vector<int>& part) {
    int n = (int)init.size(), pos = 1;
    while (pos < n && part[pos - 1] <= part[pos]) { // sorted part
        pos++;
    }
    int unsorted = pos;
    while (pos < n && init[pos] == part[pos]) { // unsorted part
        pos++;
    }
    return pos == n ? unsorted : -1;
}

void heapSort(vector<int>& heap) {
    auto it = find_if(heap.rbegin(), heap.rend(), [&](int val) { // reverse iterator
        return val <= heap[0]; // find the first element that is less than or equal to the root of the heap
    });
    int last = (int)heap.size() - 1 - (it - heap.rbegin());
    pop_heap(heap.begin(), heap.begin() + last + 1);
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
        print(init);
    } else {
        cout << "Heap Sort\n";
        heapSort(part);
        print(part);
    }

    return 0;
}
// @pintia code=end
