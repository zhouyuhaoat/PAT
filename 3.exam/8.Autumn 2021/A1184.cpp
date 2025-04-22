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
    int add, len; // address, length
};

int main(int argc, char const *argv[]) {

    int n, k;
    cin >> n >> k;
    vector<arr> d(n);
    int size = 0; // total size of the array
    for (int i = 0; i < n; i++) {
        cin >> d[i].add >> d[i].len;
        size += d[i].len;
    }
    int ans = 1; // the number of arrays that initialized
    for (int q = 0; q < k; q++) {
        int v;
        cin >> v;
        if (v >= size) { // [0, size)
            cout << "Illegal Access\n";
            continue;
        }
        int sum = 0; // dynamic size
        for (int i = 0; i < n; i++) { // 0-th array
            sum += d[i].len;
            if (v < sum) { // find the array
                cout << d[i].add + (v - (sum - d[i].len)) * 4 << "\n";
                // sum - d[i].len: the start address of the array
                // v - (sum - d[i].len): the offset of the element
                // * 4: the size of each element, 4 bytes
                ans = max(ans, i + 1);
                break;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
