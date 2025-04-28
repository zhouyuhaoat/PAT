/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 19:47:38
 *	modified:	2023-04-13 22:49:31
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1184 Arrays and Linked Lists
*/

#include <iostream>
#include <vector>

using namespace std;

struct arr { // array
    int addr, size;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<arr> data(n);
    int size = 0; // total size of the array
    for (int i = 0; i < n; i++) {
        cin >> data[i].addr >> data[i].size;
        size += data[i].size;
    }
    int res = 1; // the number of arrays that initialized
    for (int q = 0; q < k; q++) {
        int v;
        cin >> v;
        if (v >= size) { // [0, size)
            cout << "Illegal Access\n";
            continue;
        }
        int sum = 0; // dynamic size
        for (int i = 0; i < n; i++) { // 0-th array
            sum += data[i].size;
            if (v < sum) { // find the array
                cout << data[i].addr + (v - (sum - data[i].size)) * 4 << "\n";
                // sum - data[i].size: the start address of the array
                // v - (sum - data[i].size): the offset of the element
                // * 4: the size of each element, 4 bytes
                res = max(res, i + 1);
                break;
            }
        }
    }
    cout << res << "\n";

    return 0;
}
