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

bool insertionSort(vector<int>& init, vector<int>& part) {
    for (int i = 2; i < (int)init.size(); i++) {
        sort(init.begin(), init.begin() + i);
        if (init == part) {
            sort(init.begin(), init.begin() + i + 1);
            return true;
        }
    }
    return false;
}

void downAdjust(vector<int>& heap, int lo, int hi) { // of max heap
    int i = lo, j = 2 * i + 1;
    while (j <= hi) {
        if (j + 1 <= hi && heap[j + 1] > heap[j]) { // max child
            j++;
        }
        if (heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j, j = 2 * i + 1;
        } else {
            break;
        }
    }
}

/*
    heap sort
    1. divides its input into a sorted and an unsorted region
    2. iteratively shrinks the unsorted region by
        1. extracting the largest element
            1. use a heap data structure rather than a linear-time search
            2. to find the maximum
        2. moving that to the sorted region
    3. prerequisite: the unsorted region must be a max heap
*/
void heapSort(vector<int>& heap) {
    int last = (int)heap.size() - 1; // find the last element that is not in the right place
    while (last > 0 && heap[last] > heap[0]) {
        last--;
    }
    // [0, last]: unsorted & max heap; [last + 1, n - 1]: sorted
    swap(heap[0], heap[last]); // move the largest element to the sorted region
    downAdjust(heap, 0, last - 1); // adjust the heap to maintain the max heap property
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
    if (insertionSort(init, part)) {
        cout << "Insertion Sort\n";
        print(init);
    } else {
        heapSort(part);
        cout << "Heap Sort\n";
        print(part);
    }

    return 0;
}
// @pintia code=end
