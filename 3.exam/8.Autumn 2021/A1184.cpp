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

struct Array {
    int addr, size;
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<Array> array(n);
    int totalSize = 0;
    for (int i = 0; i < n; i++) {
        cin >> array[i].addr >> array[i].size;
        totalSize += array[i].size;
    }
    int res = 1; // the number of arrays that initialized
    while (k--) {
        int size;
        cin >> size;
        if (size >= totalSize) { // [0, totalSize)
            cout << "Illegal Access\n";
            continue;
        }
        int dynamicSize = 0;
        for (int i = 0; i < n; i++) { // from the 0-th array
            dynamicSize += array[i].size;
            if (size < dynamicSize) { // find the array
                cout << array[i].addr + (size - (dynamicSize - array[i].size)) * 4 << "\n";
                /*
                    1. dynamicSize - array[i].size: the start address of the array
                    2. size - (dynamicSize - array[i].size): the offset of the element
                    3. * 4: the size of each element, 4 bytes
                */
                res = max(res, i + 1);
                break;
            }
        }
    }
    cout << res << "\n";

    return 0;
}
